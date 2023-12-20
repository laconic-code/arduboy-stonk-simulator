/*
 * MIT License
 *
 * Copyright (c) 2023 Benjamin Martin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "Arduboy2.h"
#include "inc/Config.hpp"
#include "inc/Sprites.h"
#include "inc/Messages.hpp"
#include "inc/Types.hpp"
#include "inc/Ticker.hpp"
#include "inc/Dictionary.h"
#include "inc/Dictionary.c"
#include "inc/Decompress.h"
#include "inc/Decompress.c"

// TODO:
//
// Bugs:
//
// Perf:
//   Showing the stocks total is expensive due to string printing
//   options are:
//     1. make own screen. most performant, feels like spreadsheet (boring)
//     2. check to see if I need to redraw a section of the screen and
//        only draw that. ex. drawMrStonk() would clear is area (including
//        panik zone). the menu would only black out its background when
//        a change occurs. Ticker would only black out its section if
//        moving. this would involve removing arduboy.display(true)
//     ticker is about 25% (40% w/ background)
//     menu is about 40%
//     buy/sell is about 30%
//     normally sitting around 25% utilization
//
// Known Issues:
//   The graph is not accurate after a base value or step size
//     edit by the news update. this can be misleading but I am
//     not fixing it right now as it isn't that big a deal.
//     Possible solutions include resizing the graph when
//     invalidated by news item (calculation heavy). OR
//     wipe the graph and start from the left side
//     OR 'stretch' it to fit.
//
// Wishlist:
//   "AI" stockbroker that invests all your cash randomly
//   Window showing small graphs of all stocks
//   Window showing stock value 
//   shrink graph and add value lines? would need to shift when graph goes up/dwn
//   little +/- dollar amount that wafts slowly upwards on buy/sell
//   different versions of text "panik" overlayed on dude while panicking
//   make buying stocks make them more expensive
//   make selling stocks make them cheaper
//   sounds of some kind?
//   companies going bankrupt / out of business
//     (replaced with new company)
//   choosing prototypes of stocks (high risk+high reward etc) at startup
//   stock inertia
//   track amortized stock value for each company so you can see
//     your gains/losses
//     bonus: game over if you currently have lost 1 Mil (same success screen)
//   add stock that always loses value as soon as you buy (caps max value)
//   cheats

// if I have to do an info screen, maybe:
// Asset  Held      Value
//   GME  50000     $100.00K  ^
//   ACT  50000     $100.00K  |
//   INT  50000     $100.00K  |
//   ARD  50000     $100.00K  v
//    3M  50000     $100.00K
//    4M  50000     $100.00K
//  Cash            $200.00K
// Total           +$800.00K
//
// too much like looking at a spreadsheet though so I'd rather not

/////////////
// Structs //
/////////////

struct Company_t {
  char name[5];
  // current value of the stock / 100
  // capped between [0, 50000]
  money_t baseline;
  // value of a single step / 100
  // best kept between [0, 15000]
  money_t stepsize;
  // how many step sizes the stock can swing in a single tick.
  // note: one of the largest swings was ~25%.
  uint8_t volatility;
  // maximum amount of volatility
  uint8_t maxVolatility;
  // how much stock the player owns
  uint16_t held;
  // the 'actual' current value of this stock with a bit of random
  // value tacked in so it doesn't look clean to the user.
  // capped between [0, 50000 + stepsize]
  money_t value;
  // history for the stock ticker
  int8_t history[GRAPH_POINTS];
};

// why does only this function require the struct
// specifier for the type?
inline int8_t Company_currentValue(struct Company_t* self) {
  return self->history[GRAPH_POINTS - 1];
}

// generate a new stock tick value based on the current value
// and push it into the history, shifting others back one index
void Company_pushHistory(Company_t* company, int8_t bias = 0) {
  int8_t currValue = Company_currentValue(company);

  // shift history back one to make room
  for (uint8_t i = 1; i < GRAPH_POINTS; ++i) {
    company->history[i-1] = company->history[i];
  }

  // generate how much the graph will move
  int8_t delta_steps = 0;
  while (delta_steps == 0) {
    delta_steps = random(
      -((int8_t) company->volatility) + bias,
       ((int8_t) company->volatility) + bias + 1);
  }
  int8_t next = currValue + delta_steps;

  // remember that positive steps are value losses (graph down)
  // and negative steps are value increases (graph up)
  money_t delta = -((money_t) delta_steps) * company->stepsize;
  company->baseline = addClamp<money_t>(
    company->baseline,
    delta,
    STOCK_MIN_VALUE,
    STOCK_MAX_VALUE);

  // put a bit of variance on the value so the user doesn't
  // see nice clean values; provided this doesn't push
  // us over the max value
  company->value = addClamp<money_t>(
    company->baseline,
    random(0, company->stepsize),
    STOCK_MIN_VALUE,
    STOCK_MAX_VALUE);

  // make sure we don't go over the max or min cash values
  if (company->baseline == STOCK_MAX_VALUE) {
    next = GRAPH_MIN;
  } else if (company->baseline == STOCK_MIN_VALUE) {
    next = GRAPH_MAX;
  }

  // insert new value at end of the table
  company->history[GRAPH_POINTS - 1] = next;

  if (next > GRAPH_MAX && company->baseline) {
    // off the bottom of the graph, shift up
    int8_t delta = next - GRAPH_MAX;
    for (uint8_t i = 0; i < GRAPH_POINTS; i++) {
      company->history[i] -= delta;
    }

  } else if (next < GRAPH_MIN) {
    // off the top of the graph, shift down
    int8_t delta = GRAPH_MIN - next;
    for (uint8_t i = 0; i < GRAPH_POINTS; i++) {
      company->history[i] += delta;
    }
  }
}

char const* getMoneyAsString(money_t const& value, bool includeDollar) {
  // constexpr uint8_t len = sizeof("$000.00S");
  // static char buff[len];
  // uint16_t dollars = value / 100;
  // uint16_t cents = value % 100;
  // snprintf(buff, len, "$%3u.%02u", dollars, cents);
  // return buff;

  constexpr uint8_t len = sizeof("000.00S");
  static char buff[len];
  uint16_t dollars;
  uint16_t cents;
  char suffix;

  buff[0] = '$';

  if (value < 100000) {
    dollars = value / 100;
    cents = value % 100;
    suffix = ' ';
  } else if (value < 100000000) {
    dollars = value / 1000 / 100;
    cents = value / 1000 % 100;
    suffix = 'K';
  } else if (value < 100000000000) {
    dollars = value / 1000000 / 100;
    cents = value / 1000000 % 100;
    suffix = 'M';
  } else {
    dollars = value / 1000000000 / 100;
    cents = value / 1000000000 % 100;
    suffix = 'B';
  }
  if (suffix != ' ') {
    snprintf(&(buff[0])+1, len, "%u.%02u%c", dollars, cents, suffix);
  } else {
    snprintf(&(buff[0])+1, len, "%u.%02u", dollars, cents);
  }
  
  return includeDollar ? buff : &(buff[0]) + 1;
}

/////////////
// Globals //
/////////////

Arduboy2 arduboy;
uint8_t gTimer;
uint8_t gStonkMode;
uint8_t gActiveCompany;
uint8_t gGameMode;
uint64_t gMoney;
char gNewsTickerTemplateBuffer[TICKER_STRLEN];
char gNewsTickerBuffer[TICKER_STRLEN];
uint8_t gNewsTickerTarget;
uint8_t gNewsTickerCounter;
uint16_t gBuySellSubmenu;
uint16_t gBuySellCount;
uint8_t gResourceIndex;
uint8_t gResourceView;
Ticker gTicker;
uint8_t gResetCounter;
uint8_t gNewsCompanyIdx;
Company_t gCompanies[] = {
// volatility = vol
// name,  baseline, stepsize, vol, vol_max, held
  { "GME",      50,        1,   2,      50,   0}, //  low value, stable
  { "GME",      50,        1,  10,      25,   0}, //  low value, extremely volatile
  { "GME",     500,       10,   5,      10,   0}, //  low value, highly volatile
  { "GME",    2500,       50,   3,      10,   0}, //  mid value, variable
  { "GME",    7500,      500,   1,       5,   0}, //  mid value, stable
  { "GME",   10000,     1000,   1,       3,   0}  // high value, stable
};
constexpr uint8_t COMPANY_COUNT = sizeof(gCompanies) / sizeof(gCompanies[0]);

///////////
// Utils //
///////////

inline bool everyXFramesOrJustPressed(uint8_t button, uint8_t frames) {
  return arduboy.justPressed(button)
    || (arduboy.everyXFrames(frames) && arduboy.pressed(button));
}

// true if value is in the visible part of the ticker
inline bool isInGraph(int8_t point) {
  return point > GRAPH_MIN && point < GRAPH_MAX;
}

money_t getTotalAssetValue() {
    money_t total = 0;
    for (uint8_t i = 0; i < COMPANY_COUNT; ++i) {
      Company_t* company = &gCompanies[i];
      total += company->held * company->value;
    }
    total += gMoney;
    return total;
}

void setup() {
  arduboy.begin();
  // arduboy.bootLogo();
  // arduboy.systemButtons();
  // arduboy.setRGBled(0, 0, 0);
  // arduboy.audio.begin();
  // arduboy.setFrameRate(30);
  arduboy.setFrameRate(FRAMERATE);
  gTimer = LOGO_FRAMES;
  gGameMode = GAMEMODE_LOGO;
}

void setupCompanyNames() {
  for (uint8_t i = 0; i < COMPANY_COUNT; ++i) {
    rename:

    for (uint8_t j = 0; j < 3; ++j) {
      gCompanies[i].name[j] = random('A', 'Z' + 1);
    }

    // 25% chance to have a 4 letter name
    if (random(0, 4) == 3) {
      gCompanies[i].name[3] = random('A', 'Z' + 1);
    } else {
      gCompanies[i].name[3] = '\0';
    }

    // make sure the names are unique
    for (uint8_t k = 0; k < i; ++k) {
      if (strcmp(gCompanies[i].name, gCompanies[k].name) == 0) {
        goto rename;
      }
    }
  }
}

void setupGlobals() {
  Arduboy2::initRandomSeed();
  gNewsTickerCounter = 0;
  gNewsTickerTarget = TICKER_STARTUP_DELAY;
  gStonkMode = STONKMODE_GOOD;
  gActiveCompany = 0;
  gResourceIndex = 0;
  gResourceView = RESOURCES_VIEW_CASH;
  gMoney = INITIAL_MONEY;
  gBuySellSubmenu = BUYSELL_MENU_ENTRY100;
  gBuySellCount = BUYSELL_MIN;
  gTicker.init(TICKERWIN_OFFSET_X, TICKERWIN_OFFSET_Y, TICKERWIN_WIDTH);
  gNewsCompanyIdx = NO_NEWS_COMPANY;
  gResetCounter = RESET_COUNTDOWN_FRAMES;
  setupCompanyNames();
  for (uint8_t i = 0; i < COMPANY_COUNT; ++i) {
    for (uint8_t j = 0; j < GRAPH_POINTS; ++j) {
      Company_pushHistory(&gCompanies[i]);
    }
  }
}

void drawTitle() {
  Arduboy2::drawCompressed(0, 0, Splash);
  // Arduboy2::drawBitmap(0, 0, Splash, 128, 64);
  arduboy.setTextSize(1);
  if (arduboy.pressed(UP_BUTTON)) {
    arduboy.setCursor(0, 0);
    arduboy.print(VERSION);
  }
}

void drawMrStonk() {
  // finally draw our handsome boi
  if (gStonkMode == STONKMODE_GOOD) {
    Arduboy2::drawBitmap(0, 0, StonksGood, 48, 64);
  } else if (gStonkMode == STONKMODE_BAD) {
    Arduboy2::drawBitmap(0, 0, StonksBad, 48, 64);
  } else if (gStonkMode == STONKMODE_AMAZING) {
    Arduboy2::drawBitmap(0, 0, StonksAmazing, 48, 64);
  } else if (gStonkMode == STONKMODE_PANIK) {
    int8_t jiggleX = random(-1, 2);
    int8_t jiggleY = random(-1, 2);
    Arduboy2::drawBitmap(0 + jiggleX, 0 + jiggleY, StonksPanik, 48, 64);
  }
}

void drawGraph(Company_t* company) {
  // draw the company name, 3-4 characters
  arduboy.setCursor(NAME_OFFSET_X, NAME_OFFSET_Y);
  arduboy.print(company->name);

  // draw the company stock change direction indicator
  int8_t direction = company->history[GRAPH_POINTS - 2] - company->history[GRAPH_POINTS - 1];
  Arduboy2::drawBitmap(
    STOCKARROW_OFFSET_X, STOCKARROW_OFFSET_Y,
    (direction < 0) ? DownArrow : UpArrow,
    8, 8);

  // draw the company stock value
  arduboy.setCursor(STOCKVALUE_OFFSET_X, STOCKVALUE_OFFSET_Y);
  arduboy.print(getMoneyAsString(company->value, true));

  // Draw the box around the stock graph
  // left line
  Arduboy2::drawRect(
    GRAPH_OFFSET_X - 1,
    GRAPH_OFFSET_Y - 1,
    GRAPH_WIDTH + 1,
    GRAPH_HEIGHT + 1);

  // Now draw the actual stock ticker line graph
  for (uint8_t i = 1; i < GRAPH_POINTS; ++i) {
    bool first = isInGraph(company->history[i-1]);
    bool second = isInGraph(company->history[i]);
    if (first && second) {
      Arduboy2::drawLine(
        GRAPH_OFFSET_X+i-1, company->history[i-1],
        GRAPH_OFFSET_X+i, company->history[i]);
    } else if (first || second) {
      Arduboy2::drawLine(
        GRAPH_OFFSET_X+i-1, clamp(company->history[i-1], GRAPH_MIN, GRAPH_MAX),
        GRAPH_OFFSET_X+i, clamp(company->history[i], GRAPH_MIN, GRAPH_MAX));
    }
  }
}

void drawNews() {
  gTicker.draw(arduboy);
}

void drawBuySell() {
  Company_t* company = &gCompanies[gActiveCompany];

  uint16_t count;
  if (gBuySellSubmenu == BUYSELL_MENU_ALLIN) {
    count = min(
      (gMoney / (uint64_t) company->value) + company->held,
      BUYSELL_MAX);
  } else if (gBuySellSubmenu == BUYSELL_MENU_CASHOUT) {
    count = 0;
  } else {
    count = gBuySellCount;
  }

  // clear the background
  arduboy.fillRect(
    BUYSELLWIN_OFFSET_X + 1,
    BUYSELLWIN_OFFSET_Y + 1,
    BUYSELLWIN_WIDTH - 2,
    BUYSELLWIN_HEIGHT - 2,
    BLACK);

  // amount to buy/sell
  //
  //    ^
  // amount
  //    v

  // up and value entry arrows
  if (gBuySellSubmenu >= BUYSELL_MENU_ENTRY1 && gBuySellSubmenu <= BUYSELL_MENU_ENTRY10000) {
    uint8_t entryOffset = (BUYSELL_MENU_ENTRY10000 - gBuySellSubmenu) * 6;

    Arduboy2::drawBitmap(
      BUYSELL_OFFSET_X + entryOffset - 1,
      BUYSELL_OFFSET_Y - 8,
      UpArrow, 8, 8);

    Arduboy2::drawBitmap(
      BUYSELL_OFFSET_X + entryOffset - 1,
      BUYSELL_OFFSET_Y + 8 - 1,
      DownArrow, 8, 8);

    constexpr uint8_t len = sizeof("00000");
    char buff[len];
    snprintf(buff, len, "%5u", count);
    arduboy.setCursor(BUYSELL_OFFSET_X + 1, BUYSELL_OFFSET_Y);
    arduboy.print(buff);

  } else if (gBuySellSubmenu == BUYSELL_MENU_ALLIN) {
    arduboy.setCursor(BUYSELLWIN_OFFSET_X + 6, BUYSELL_OFFSET_Y);
    arduboy.print("ALL IN!");

  } else if (gBuySellSubmenu == BUYSELL_MENU_CASHOUT) {
    arduboy.setCursor(BUYSELLWIN_OFFSET_X + 2, BUYSELL_OFFSET_Y);
    arduboy.print("I'M OUT!");
  }

  // money change result

  // Figure out how much the user's current
  // selection is worth
  uint16_t countDelta = (company->held > count)
    ? company->held - count
    : count - company->held;
  money_t delta = company->value * countDelta;
  char const* moneystr = getMoneyAsString(delta, false);

  arduboy.setCursor(
    BUYSELLWIN_OFFSET_X + 4,
    BUYSELLWIN_OFFSET_Y + 2);
  if (count > company->held) {
    arduboy.print("-");
    arduboy.print(moneystr);
  } else if (count < company->held) {
    arduboy.print("+");
    arduboy.print(moneystr);
  }

  // the window separators

  arduboy.drawRect(
    BUYSELLWIN_OFFSET_X,
    BUYSELLWIN_OFFSET_Y,
    BUYSELLWIN_WIDTH,
    BUYSELLWIN_HEIGHT);

  Arduboy2::drawFastHLine(
    BUYSELLWIN_OFFSET_X,
    BUYSELLWIN_OFFSET_Y + (BUYSELLWIN_HEIGHT / 4) + 2,
    BUYSELLWIN_WIDTH);
}

void drawResources() {
  constexpr uint8_t len = 16;
  char buff[len];

  // arduboy.fillRect(
  //   RESOURCEWIN_OFFSET_X + 1,
  //   RESOURCEWIN_OFFSET_Y + 1,
  //   RESOURCEWIN_WIDTH - 2,
  //   RESOURCEWIN_HEIGHT - 2,
  //   BLACK);

  // money strings are 8 characters, 64 px "$000.00S"
  // company+stock is 10 characters, 80 px "CCCC HHHHH"
  // 6 companys and 2 money values can't fit on the same line
  // so sadly we are scrolling | or we can show the stock ticker above
  // and let the player page through them
  if (gResourceView == RESOURCES_VIEW_CASH) {
    arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(0*10));
    arduboy.print("Cash:");

    snprintf(buff, len, "  %10s", getMoneyAsString(gMoney, true));
    arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(1*10));
    arduboy.print(buff);

    arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(2*10));
    arduboy.print("Total:");

    snprintf(buff, len, "  %10s", getMoneyAsString(getTotalAssetValue(), true));
    arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(3*10));
    arduboy.print(buff);

  } else if (gResourceView == RESOURCES_VIEW_HELD) {
    uint8_t idx = gResourceIndex;
    for (uint8_t i = 0; i < RESOURCEWIN_VISIBLE; ++i, ++idx) {
      if (idx == 0) {
        snprintf(buff, len, "Held:");
      } else if (idx <= COMPANY_COUNT) {
        snprintf(buff, len, "%-4s   %5u",
          gCompanies[idx-1].name,
          gCompanies[idx-1].held);
      } else {
        break;
      }
      arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(i*10));
      arduboy.print(buff);
    }

  } else if (gResourceView == RESOURCES_VIEW_VALUE) {
    uint8_t idx = gResourceIndex;
    for (uint8_t i = 0; i < RESOURCEWIN_VISIBLE; ++i, ++idx) {
      if (idx == 0) {
        snprintf(buff, len, "Value:");
      } else if (idx <= COMPANY_COUNT) {
        snprintf(buff, len, "%-4s %7s",
          gCompanies[idx-1].name,
          getMoneyAsString(gCompanies[idx-1].value, true));
      } else {
        break;
      }
      arduboy.setCursor(RESOURCEWIN_OFFSET_X+3, RESOURCEWIN_OFFSET_Y+4+(i*10));
      arduboy.print(buff);
    }
  }

  arduboy.drawRect(
    RESOURCEWIN_OFFSET_X, 
    RESOURCEWIN_OFFSET_Y,
    RESOURCEWIN_WIDTH,
    RESOURCEWIN_HEIGHT);
}

bool checkGameOver() {
  if (getTotalAssetValue() > GAME_SUCCESS_ASSET_VALUE) {
    gGameMode = GAMEMODE_GAMEOVER;
    return true;
  }
  return false;
}

void updateNews() {
  gTicker.update();

  if (arduboy.everyXFrames(FRAMERATE) && gTicker.isIdle()) {
    // update the news ticker clock
    // every second
    gNewsTickerCounter += 1;
  }

  if (gTicker.isIdle() && gNewsCompanyIdx != NO_NEWS_COMPANY) {
    Company_t* company = &gCompanies[gNewsCompanyIdx];
    gNewsCompanyIdx = NO_NEWS_COMPANY;

        // determine what happens to the stock
    uint8_t event = random(0, 3);
    if (event == 0) {
      // adjust baseline up/down by some number of steps immediately
      // invalidates graph

      money_t adjustmentPercentage = random(0, NEWS_ADJUST_PERCENTAGE) + 1;
      money_t delta = (company->baseline * adjustmentPercentage) / 100;
      if (random(0, 2)) {
        delta *= -1;
      }

      company->baseline = clamp<money_t>(
        STOCK_MIN_VALUE,
        company->baseline + delta,
        STOCK_MAX_VALUE);

    } else if (event == 1) {
      // // adjust step size by some percentage of current step size
      // // invalidates graph

      // money_t adjustmentPercentage = random(0, NEWS_ADJUST_PERCENTAGE) + 1;
      // money_t delta = (company->stepsize * adjustmentPercentage) / 100;
      // if (random(0, 2)) {
      //   delta *= -1;
      // }

      // company->stepsize = clamp<money_t>(
      //   STOCK_MIN_STEPSIZE,
      //   company->stepsize + delta,
      //   STOCK_MAX_STEPSIZE);

    } else if (event == 2) {
      // adjust volatility
      company->volatility = random(1, company->maxVolatility);
      
    }

  }

  if (gNewsTickerCounter == gNewsTickerTarget) {
    gNewsTickerCounter = 0;
    gNewsTickerTarget = TICKER_PERIOD + random(
      -TICKER_PERIOD_VARIANCE,
      TICKER_PERIOD_VARIANCE);

    // select our lucky contestant
    gNewsCompanyIdx = random(0, COMPANY_COUNT);
    Company_t* company = &gCompanies[gNewsCompanyIdx];

    // build the string the news scroller shows

    // copy compressed template string into memory
    strcpy_P(
      gNewsTickerBuffer,
      (char const*) pgm_read_word(&(Messages[random(0, Messages_COUNT)])));

    // decompress template string
    Dictionary_decompress(
      gNewsTickerTemplateBuffer,
      TICKER_STRLEN,
      gNewsTickerBuffer);

    // format template string into buffer
    snprintf(
      gNewsTickerBuffer,
      TICKER_STRLEN,
      gNewsTickerTemplateBuffer,
      company->name);

    // update the ticker window
    gTicker.setBuff(gNewsTickerBuffer);
  }
}

void updateGraph() {
  if (arduboy.everyXFrames(FRAMERATE)) {
    // occasionally variate the stock values
    // this is expensive, stagger across multiple
    // frames if it becomes an issue
    for (uint8_t i = 0; i < COMPANY_COUNT; ++i) {
      Company_pushHistory(&gCompanies[i]);
    }
  }

  int8_t currValue = Company_currentValue(&gCompanies[gActiveCompany]);

  // figure out how mr. man is reacting to his decisions.
  constexpr int8_t thresholdAmazing = GRAPH_MIN + (GRAPH_HEIGHT * 0.1);
  constexpr int8_t thresholdBad = GRAPH_MAX - (GRAPH_HEIGHT * 0.2);
  constexpr int8_t thresholdPanik = GRAPH_MAX - (GRAPH_HEIGHT * 0.1);
  if (currValue < thresholdAmazing) {
    gStonkMode = STONKMODE_AMAZING;
  } else if (currValue >= thresholdPanik) {
    gStonkMode = STONKMODE_PANIK;
  } else if (currValue >= thresholdBad) {
    gStonkMode = STONKMODE_BAD;
  } else {
    gStonkMode = STONKMODE_GOOD;
  }
}

void loopLogo();
void loopTitle();
void loopGraph();
void loopBuySell();
void loopResources();
void loopGameOver();
void loop() {
  if (!arduboy.nextFrame()) {
    arduboy.idle();
    return;
  }

  if (arduboy.pressed(LEFT_BUTTON | RIGHT_BUTTON)) {
    gResetCounter -= 1;
    if (gResetCounter == 0) {
      gTimer = LOGO_FRAMES;
      gGameMode = GAMEMODE_LOGO;
      gResetCounter = RESET_COUNTDOWN_FRAMES;
      return;
    }
  } else {
    gResetCounter = RESET_COUNTDOWN_FRAMES;
  }

  arduboy.pollButtons();
  if (gGameMode == GAMEMODE_LOGO) {
    loopLogo();
  } else if (gGameMode == GAMEMODE_TITLE) {
    loopTitle();
  } else if (gGameMode == GAMEMODE_GRAPH) {
    loopGraph();
  } else if (gGameMode == GAMEMODE_BUYSELL) {
    loopBuySell();
  } else if (gGameMode == GAMEMODE_RESOURCES) {
    loopResources();
  } else if (gGameMode == GAMEMODE_GAMEOVER) {
    loopGameOver();
  }

}

void loopLogo() {
  if (gTimer == 0 || arduboy.anyPressed(A_BUTTON | B_BUTTON)) {
    gGameMode = GAMEMODE_TITLE;
    gTimer = 0;
  } else {
    if (gTimer == LOGO_FRAMES) {
      Arduboy2::clear();
      Arduboy2::drawCompressed(0, 0, Logo);
      Arduboy2::display();
    }
    gTimer -= 1;
  }
}

void loopTitle() {
  if (gTimer == 0) {
    // save a bit of CPU usage by only drawing once
    arduboy.clear();
    drawTitle();
    arduboy.display();
    gTimer = 1;
  }

  if (arduboy.justPressed(A_BUTTON)) {
    setupGlobals();
    gGameMode = GAMEMODE_GRAPH;
    gTimer = 0;
  }

}

void loopGraph() {
  updateNews();
  updateGraph();

  if (arduboy.justPressed(UP_BUTTON)) {
    #ifdef TESTING
    // tick current stock up in value
    Company_pushHistory(&gCompanies[gActiveCompany], -1);
    gMoney += 10000000;
    #endif
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    #ifdef TESTING
    // tick current stock down in value
    Company_pushHistory(&gCompanies[gActiveCompany], 1);
    #endif
  }
  // player selected previous company
  if (arduboy.justPressed(LEFT_BUTTON)) {
    gActiveCompany = gActiveCompany == 0
      ? COMPANY_COUNT - 1
      : gActiveCompany - 1;
  }
  // player selected next company
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    gActiveCompany = gActiveCompany == COMPANY_COUNT - 1
      ? 0
      : gActiveCompany + 1;
  }
  // open buy sell
  if (arduboy.justPressed(A_BUTTON)) {
    gGameMode = GAMEMODE_BUYSELL;
    gBuySellSubmenu = BUYSELL_MENU_ENTRY100;
    gBuySellCount = gCompanies[gActiveCompany].held;
  }
  if (arduboy.justPressed(B_BUTTON)) {
    gGameMode = GAMEMODE_RESOURCES;
  }

  // see if the player has gathered 1Mil in assets.
  // we only check here since we want to wait
  // until after they have made a purchase
  checkGameOver();

  //////////
  // Draw //
  //////////

  Company_t* company = &gCompanies[gActiveCompany];

  arduboy.display(true);
  drawGraph(company);
  drawMrStonk();
  drawNews();
}

void loopBuySell() {
  updateNews();
  updateGraph();
  Company_t* company = &gCompanies[gActiveCompany];

  // number entry mode

  if (arduboy.justPressed(DOWN_BUTTON)) {
    uint16_t delta;
    switch (gBuySellSubmenu) {
      case BUYSELL_MENU_ENTRY10000:
        delta = 10000; break;
      case BUYSELL_MENU_ENTRY1000:
        delta = 1000; break;
      case BUYSELL_MENU_ENTRY100:
        delta = 100; break;
      case BUYSELL_MENU_ENTRY10:
        delta = 10; break;
      default:
        delta = 1; break;
    }

    if (gBuySellCount > delta) {
      gBuySellCount -= delta;
    } else {
      gBuySellCount = BUYSELL_MIN;
    }

  } else if (arduboy.justPressed(UP_BUTTON)) {
    uint16_t delta;
    switch (gBuySellSubmenu) {
      case BUYSELL_MENU_ENTRY10000:
        delta = 10000; break;
      case BUYSELL_MENU_ENTRY1000:
        delta = 1000; break;
      case BUYSELL_MENU_ENTRY100:
        delta = 100; break;
      case BUYSELL_MENU_ENTRY10:
        delta = 10; break;
      default:
        delta = 1; break;
    }

    if (gBuySellCount < (BUYSELL_MAX - delta)) {
      gBuySellCount += delta;
    } else {
      gBuySellCount = BUYSELL_MAX;
    }

  } else if (arduboy.justPressed(LEFT_BUTTON)) {
    if (gBuySellSubmenu < BUYSELL_MENU_ALLIN) {
      gBuySellSubmenu += 1;
    }

  } else if (arduboy.justPressed(RIGHT_BUTTON)) {
    if (gBuySellSubmenu > BUYSELL_MENU_CASHOUT) {
      gBuySellSubmenu -= 1;
    }

  } else if (arduboy.justPressed(A_BUTTON)) {
    // all values have been verified before this point
    // no need to do bounds checking.
    uint16_t newHeld;
    if (gBuySellSubmenu == BUYSELL_MENU_ALLIN) {
      newHeld = min(
        (gMoney / (uint64_t) company->value) + company->held,
        BUYSELL_MAX);

    } else if (gBuySellSubmenu == BUYSELL_MENU_CASHOUT) {
      newHeld = 0;

    } else {
      newHeld = gBuySellCount;
    }

    if (newHeld > company->held) {
      // buying
      uint16_t delta = newHeld - company->held;
      company->held += delta;
      gMoney -= (money_t) company->value * (money_t) delta;

    } else if (newHeld < company->held) {
      // selling
      uint16_t delta = company->held - newHeld;
      company->held -= delta;
      gMoney += (money_t) company->value * (money_t) delta;
    }

    gGameMode = GAMEMODE_GRAPH;

  } else if (arduboy.justPressed(B_BUTTON)) {
    gGameMode = GAMEMODE_GRAPH;
  }

  // clamp max value to how much the player can buy
  uint64_t maxPurchase = gMoney / (uint64_t) company->value;
  uint64_t maxPossible = maxPurchase + company->held;
  if ((uint64_t) gBuySellCount > maxPossible) {
    gBuySellCount = min(maxPossible, BUYSELL_MAX);
  }

  // Draw

  arduboy.display(true);
  drawGraph(company);
  drawMrStonk();
  drawNews();
  drawBuySell();
}

void loopResources() {
  updateGraph();
  updateNews();
  
  if (everyXFramesOrJustPressed(DOWN_BUTTON, FRAMERATE/4)) {
    gResourceIndex +=
      (gResourceIndex == (RESOURCEWIN_ENTRIES - RESOURCEWIN_VISIBLE))
      ? 0 : 1;
  } else if (everyXFramesOrJustPressed(UP_BUTTON, FRAMERATE/4)) {
    gResourceIndex -=
      (gResourceIndex == 0)
      ? 0 : 1;
  }

  if (arduboy.justPressed(RIGHT_BUTTON)) {
    gResourceView = (gResourceView == RESOURCES_VIEW_VALUE)
      ? 0 : gResourceView + 1;
  } else if (arduboy.justPressed(LEFT_BUTTON)) {
    gResourceView = (gResourceView == 0)
      ? RESOURCES_VIEW_VALUE : gResourceView - 1;
  }

  if (arduboy.justPressed(B_BUTTON) || arduboy.justPressed(A_BUTTON)) {
    gGameMode = GAMEMODE_GRAPH;
  }

  arduboy.display(true);
  drawMrStonk();
  drawNews();
  drawResources();
}

void loopGameOver() {
  if (gTimer == 0) {
    gTimer = 1;
    arduboy.clear();
    Arduboy2::drawCompressed(0, 0, DiamondHands);
    Arduboy2::drawFastHLine(0, 54, WIDTH);
    Arduboy2::setCursor(2, 56);
    arduboy.print("You are a millionare!");
    arduboy.display();
  }

  if (arduboy.justPressed(A_BUTTON)) {
    gGameMode = GAMEMODE_TITLE;
    gTimer = 0;
  }
}

