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
#include <Arduboy2.h>
#include "Config.hpp"

struct Ticker {
    const uint8_t CELL_WIDTH_PX = 6;
    const uint8_t CELL_HEIGHT_PX = 8;
    const uint8_t WIN_HEIGHT = 11;
    const uint8_t SCROLL_SPEED = 1; // advance every 1/3 second
    uint8_t x;
    uint8_t y;
    uint8_t width;
    char const* buff;
    uint8_t buffStartIdx;
    uint8_t buffDisplayLen;
    uint8_t pxIdx;
    uint8_t maxChars;
    bool trailingOff;

    void init(uint8_t x, uint8_t y, uint8_t w) {
        this->x = x;
        this->y = y;
        this->width = w;
        this->buff = NULL,
        this->buffStartIdx = 0;
        this->buffDisplayLen = 0;
        this->pxIdx = 0;
        this->maxChars = (w / Ticker::CELL_WIDTH_PX) + 1;
        this->trailingOff = false;
    }

    void setBuff(char const* buff) {
        this->buff = buff;
        this->buffStartIdx = 0;
        this->buffDisplayLen = 1;
        this->pxIdx = 0;
        this->trailingOff = false;
    }

    bool isIdle() {
        return this->buff == NULL;
    }

    void update() {
        if (this->buff == NULL) {
            return;
        }

        if (this->trailingOff && Arduboy2::everyXFrames(FRAMERATE)) {
            this->trailingOff = false;
            this->buff = NULL;
            return;
        }

        if (Arduboy2::everyXFrames(SCROLL_SPEED)) {
            this->pxIdx += 1;

            if (this->pxIdx == CELL_WIDTH_PX) {
                this->pxIdx = 0;

                if (this->buffDisplayLen < this->maxChars) {
                    this->buffDisplayLen += 1;
                } else if (buff[this->buffStartIdx] != '\0') {
                    this->buffStartIdx += 1;
                }

                if (buff[this->buffStartIdx] == '\0') {
                    this->trailingOff = true;
                }
            }
        }
    }

    void draw(Arduboy2& arduboy) {
        if (this->buff == NULL) {
            return;
        }

        // clear the background
        arduboy.fillRect(
            this->x + 1,
            this->y + 1,
            this->width - 2,
            Ticker::WIN_HEIGHT - 2,
            BLACK);

        // not sure of the best way to do this, maybe:
        // save the pixel position of the cursor, start at right side of box.
        // print character and overwrite w/ black box if over the edge of
        // the valid text area.
        // decrement pixel position if not at left edge for next loop

        // save 1 char on either side for "fading" text out

        int16_t baseX = this->x + Ticker::CELL_WIDTH_PX - 1;
        int16_t cursorX = baseX;
        cursorX += this->width - Ticker::CELL_WIDTH_PX;
        cursorX -= this->buffDisplayLen * CELL_WIDTH_PX;
        cursorX -= this->pxIdx;
        arduboy.setCursor(cursorX, this->y + 2);

        for (uint8_t i = 0; i < this->buffDisplayLen; ++i) {
            if (this->buff[this->buffStartIdx + i] == '\0') {
                break;
            }
            if (arduboy.getCursorX() > baseX + this->width) {
                break;
            }

            arduboy.print(buff[this->buffStartIdx + i]);
        }

        // draw the "fade" boxes partially over characters
        arduboy.fillRect(
            this->x + 1,
            this->y + 1,
            Ticker::CELL_WIDTH_PX - 1,
            Ticker::WIN_HEIGHT - 2,
            BLACK);
        arduboy.fillRect(
            this->x + this->width - Ticker::CELL_WIDTH_PX + 1,
            this->y + 1,
            Ticker::CELL_WIDTH_PX - 2,
            Ticker::WIN_HEIGHT - 2,
            BLACK);

        // draw window border
        arduboy.drawRect(
            this->x,
            this->y,
            this->width,
            Ticker::WIN_HEIGHT);
    }

};