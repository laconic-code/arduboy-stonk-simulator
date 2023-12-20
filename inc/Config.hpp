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
#pragma once

typedef int32_t money_t;

#define VERSION "v1.0"
//#define TESTING
#define STONKMODE_GOOD      0
#define STONKMODE_BAD       1
#define STONKMODE_AMAZING   2
#define STONKMODE_PANIK     3
#define GAMEMODE_LOGO       0
#define GAMEMODE_TITLE      1
#define GAMEMODE_GRAPH      2
#define GAMEMODE_BUYSELL    3
#define GAMEMODE_RESOURCES  4
#define GAMEMODE_GAMEOVER   5
#define FRAMERATE 30
#define LOGO_FRAMES 45
#define GRAPH_OFFSET_X 56
#define GRAPH_OFFSET_Y 16
#define NAME_OFFSET_X 56
#define NAME_OFFSET_Y 4
#define STOCKARROW_OFFSET_X NAME_OFFSET_X - 10
#define STOCKARROW_OFFSET_Y NAME_OFFSET_Y + 0
#define STOCKVALUE_OFFSET_X NAME_OFFSET_X + 29
#define STOCKVALUE_OFFSET_Y NAME_OFFSET_Y + 0
#define RESOURCEWIN_OFFSET_X 51
#define RESOURCEWIN_OFFSET_Y 4
#define RESOURCEWIN_WIDTH  77
#define RESOURCEWIN_HEIGHT 46
#define RESOURCEWIN_ENTRIES 7
#define RESOURCEWIN_VISIBLE 4
#define BUYSELLWIN_OFFSET_X 0
#define BUYSELLWIN_OFFSET_Y 31
#define BUYSELLWIN_WIDTH 48 + 2
#define BUYSELLWIN_HEIGHT 33
#define BUYSELL_OFFSET_X BUYSELLWIN_OFFSET_X + 9
#define BUYSELL_OFFSET_Y BUYSELLWIN_OFFSET_Y + 18
#define BUYSELL_MAX 50000
#define BUYSELL_MIN 0
#define BUYSELL_MENU_CASHOUT      0
#define BUYSELL_MENU_ENTRY1       1
#define BUYSELL_MENU_ENTRY10      2
#define BUYSELL_MENU_ENTRY100     3
#define BUYSELL_MENU_ENTRY1000    4
#define BUYSELL_MENU_ENTRY10000   5
#define BUYSELL_MENU_ALLIN        6
#define TICKERWIN_OFFSET_X 0
#define TICKERWIN_OFFSET_Y HEIGHT - 11
#define TICKERWIN_HEIGHT 11
#define TICKERWIN_WIDTH WIDTH
#define NO_NEWS_COMPANY ((uint8_t) -1)
#define TICKER_PERIOD 25 /* time _between_ events in seconds. */
#define TICKER_PERIOD_VARIANCE 10
#define TICKER_STRLEN 128
#define TICKER_STARTUP_DELAY 2 // TICKER_PERIOD * 2 /* time before first event in seconds */
#define NEWS_ADJUST_PERCENTAGE 15 /* 1-100 */
#define STOCK_MIN_STEPSIZE 1
#define STOCK_MAX_STEPSIZE 2500
#define INITIAL_MONEY 1000000
#define RESET_COUNTDOWN_FRAMES (FRAMERATE * 3)
#define RESOURCES_VIEW_CASH  0
#define RESOURCES_VIEW_HELD  1
#define RESOURCES_VIEW_VALUE 2
constexpr money_t GAME_SUCCESS_ASSET_VALUE = 100000000;
constexpr int8_t GRAPH_WIDTH = 64;
constexpr int8_t GRAPH_HEIGHT = 32;
constexpr int8_t GRAPH_POINTS = GRAPH_WIDTH;
constexpr int8_t GRAPH_MIN = GRAPH_OFFSET_Y;
constexpr int8_t GRAPH_MAX = GRAPH_OFFSET_Y + GRAPH_HEIGHT - 1;
constexpr money_t STOCK_MAX_VALUE = 50000; /* = 500.00 */
constexpr money_t STOCK_MIN_VALUE = 1;     /* =   0.01 */