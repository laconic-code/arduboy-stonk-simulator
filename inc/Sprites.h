/*
 * This file contains representations of images in the same
 * directory. Refer to the co-located LICENSE.txt for each
 * array's corresponding terms.
 */
#pragma once

// .\down-arrow.png  width: 8 height: 8
const PROGMEM uint8_t DownArrow[] = { 0x00, 0x0c, 0x1c, 0x3c, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t DownArrow_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\up-arrow.png  width: 8 height: 8
const PROGMEM uint8_t UpArrow[] = { 0x00, 0x30, 0x38, 0x3c, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t UpArrow_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\left-arrow.png  width: 8 height: 8
const PROGMEM uint8_t LeftArrow[] = { 0x00, 0x00, 0x18, 0x3c, 0x7e, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t LeftArrow_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\right-arrow.png  width: 8 height: 8
const PROGMEM uint8_t RightArrow[] = { 0x00, 0x00, 0x7e, 0x7e, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t RightArrow_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\button-a.png  width: 8 height: 8
const PROGMEM uint8_t ButtonA[] = { 0x3c, 0x7e, 0x81, 0xf5, 0xf5, 0x81, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t ButtonA_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\button-b.png  width: 8 height: 8
const PROGMEM uint8_t ButtonB[] = { 0x3c, 0x7e, 0x81, 0xb5, 0xb5, 0xc3, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t ButtonB_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\stonks-good.png  width: 48 height: 64
const PROGMEM uint8_t StonksGood[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x28, 0x08, 0x10, 0x00, 0x00, 0xc0, 0x00, 0x10, 0x08, 0x29, 0x1e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x20, 0x40, 0x80, 0x88, 0x88, 0x47, 0x40, 0x20, 0x80, 0x70, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0xe4, 0x1c, 0x08, 0x08, 0x08, 0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x06, 0x0a, 0x14, 0x64, 0x88, 0x68, 0x10, 0x10, 0x6c, 0x82, 0x62, 0x11, 0x0d, 0x03, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x13, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x11, 0x16, 0x18, 0xf0, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x01, 0x02, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x50, 0x50, 0x90, 0x10, 0x30, 0x60, 0xa0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x3e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x63, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t StonksGood_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\stonks-bad.png  width: 48 height: 64
const PROGMEM uint8_t StonksBad[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x09, 0x2a, 0x0a, 0x10, 0x00, 0x00, 0xc0, 0x02, 0x12, 0x09, 0x29, 0x1e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x48, 0x48, 0x47, 0x80, 0x00, 0x80, 0x70, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0xe4, 0x1c, 0x08, 0x08, 0x08, 0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x06, 0x0a, 0x14, 0x64, 0x88, 0x68, 0x10, 0x10, 0x6c, 0x82, 0x62, 0x11, 0x0d, 0x03, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x13, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x11, 0x16, 0x18, 0xf0, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x01, 0x02, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x50, 0x50, 0x90, 0x10, 0x30, 0x60, 0xa0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x3e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x63, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t StonksBad_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\stonks-amazing.png  width: 48 height: 64
const PROGMEM uint8_t StonksAmazing[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x32, 0x79, 0x79, 0x69, 0x30, 0x00, 0x00, 0xc0, 0x01, 0x31, 0x7a, 0x7d, 0x6e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe8, 0xe8, 0xe7, 0xc0, 0x00, 0x80, 0x70, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0xe4, 0x1d, 0x09, 0x09, 0x09, 0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x06, 0x0a, 0x14, 0x64, 0x88, 0x68, 0x10, 0x10, 0x6c, 0x82, 0x62, 0x11, 0x0d, 0x03, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x13, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x11, 0x16, 0x18, 0xf0, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x01, 0x02, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x50, 0x50, 0x90, 0x10, 0x30, 0x60, 0xa0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x3e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x63, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t StonksAmazing_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\stonks-panik.png  width: 48 height: 64
const PROGMEM uint8_t StonksPanik[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xc0, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0xc0, 0xa0, 0x30, 0x50, 0xa0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x07, 0x02, 0x19, 0x04, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x04, 0x32, 0x79, 0x79, 0x59, 0x30, 0x00, 0x00, 0xc0, 0x01, 0x31, 0x7b, 0xfe, 0x01, 0x06, 0x00, 0x01, 0x3e, 0x40, 0xe0, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 0x08, 0x06, 0x01, 0x00, 0x03, 0x06, 0x09, 0x10, 0x10, 0xd0, 0x30, 0xc8, 0x07, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe8, 0xe8, 0xe7, 0x40, 0x00, 0x81, 0x72, 0x2c, 0xc4, 0x04, 0x04, 0x02, 0x01, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x30, 0x28, 0x44, 0x82, 0x01, 0x00, 0x00, 0x87, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0xe5, 0x1d, 0x09, 0x09, 0x08, 0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x83, 0x4c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0xf8, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x06, 0x0a, 0x14, 0x64, 0x88, 0x68, 0x10, 0x10, 0x6c, 0x82, 0x62, 0x11, 0x0d, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x13, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const PROGMEM uint8_t StonksPanik_mask[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// .\logo.png  width: 128 height: 64
const PROGMEM uint8_t Logo[] = {
0x7f,0x3f,0xc0,0x2e,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,
0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,
0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,
0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,
0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,
0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0xae,0xa3,0x4f,0xa7,0xa3,0x4b,0xa7,0xd3,
0xe9,0xe0,0xa3,0xad,0x75,0xd6,0x8e,0xee,0xec,0x52,0x49,0x25,0xe7,0xcd,0x2e,0x95,
0x54,0x72,0xac,0x29,0xb4,0xa5,0xd3,0x61,0x69,0x99,0xce,0x47,0x3b,0xf6,0x96,0xe9,
0x74,0x3e,0x56,0x85,0xb4,0xe9,0x97,0xe9,0x7c,0xb4,0xe3,0x6f,0x6b,0x9d,0xb5,0xf3,
0x29,0x52,0x45,0x36,0x9b,0x82,0xa4,0xb6,0xd6,0x59,0x3b,0x7d,0x76,0xa9,0x9c,0x53,
0x4e,0x39,0xe5,0x94,0x53,0x4e,0x39,0xe5,0x94,0x53,0x4e,0x39,0xe5,0x94,0x73,0x4a,
0x6e,0x43,0xa3,0xd4,0xe9,0x74,0x94,0xce,0x56,0xb2,0x92,0x95,0xfa,0x38,0xb3,0xd2,
0xa5,0x63,0x4d,0x3b,0x97,0x4a,0x85,0xb1,0x5c,0x2a,0xd7,0xb9,0x4e,0xce,0x29,0x5d,
0x36,0x9d,0x77,0x9c,0x8e,0x33,0x2b,0x5d,0x3a,0xd6,0xb4,0x73,0xa9,0x54,0x68,0xdc,
0x5a,0x67,0xed,0xf0,0xdd,0xd6,0x3a,0x6b,0xe7,0x4b,0x6f,0x95,0x74,0xd2,0x49,0x27,
0x5d,0x29,0xab,0xac,0xb2,0xaa,0x9c,0x74,0xd2,0x49,0x27,0x95,0x5d,0x87,0x49,0x7b,
0xe7,0x3a,0x79,0x93,0x2a,0xd7,0xb9,0xce,0x75,0x72,0x56,0xe5,0xd2,0xe9,0xbc,0x62,
0xfc,0x49,0xb3,0x95,0xec,0x64,0x74,0x49,0x29,0xd3,0xd1,0x29,0xd7,0xb9,0xce,0x75,
0x72,0x52,0x27,0xb3,0xe9,0x7c,0x30,0xd2,0xd6,0x3a,0x6b,0x87,0xef,0xb6,0xd6,0x59,
0x3b,0xfe,0xd2,0xdb,0xed,0xec,0xe9,0xed,0x76,0x2c,0xce,0x3a,0x6b,0x3e,0x9d,0x4e,
0x47,0x9c,0x4b,0xa5,0x52,0xa9,0x54,0xca,0x71,0xce,0x9a,0x4f,0x67,0xa3,0xcd,0xc7,
0x9a,0x4f,0xa7,0xd3,0xb1,0x0e,0x8b,0x6d,0xad,0xb3,0x76,0xf8,0x2e,0xbd,0xdd,0x6e,
0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,
0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,
0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,
0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,
0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,0x76,0xbb,0xdd,0x6e,0xb7,0xdb,0xed,
0x76,0x3b,0xd8,0x45
};
// bytes:436 ratio: 0.426

const PROGMEM uint8_t Logo_mask[] = {
0x7f,0x3f,0x81,0xff,0x1f
};
// bytes:5 ratio: 0.005


// .\splash.png  width: 128 height: 64
const PROGMEM uint8_t Splash[] = {
0x7f,0x3f,0x80,0xdc,0x68,0xe9,0xd4,0x9d,0x56,0x77,0x5a,0xdd,0xea,0x76,0x1d,0xe7,
0x76,0x67,0xb7,0x6e,0x3b,0xad,0x72,0x4e,0xdd,0x6a,0xbb,0x5d,0x3b,0xa9,0x28,0xa5,
0x92,0x72,0xbb,0xdc,0xae,0x95,0x9d,0xd1,0x6e,0x75,0x76,0xa9,0xe4,0xd0,0x54,0x7a,
0xbb,0xdd,0x6e,0xb7,0xdb,0x21,0xee,0xf4,0x76,0x29,0xdd,0x52,0xba,0xa5,0x92,0x63,
0x69,0xab,0xec,0xae,0x76,0xf1,0xa5,0xd7,0xdb,0xed,0x76,0xb9,0x8d,0x56,0x49,0x85,
0x24,0x25,0x15,0xa9,0x92,0x4a,0x66,0xb7,0xca,0x2a,0x3b,0x0e,0xa3,0x4d,0x47,0x9b,
0x5d,0x2a,0x25,0x97,0xdb,0x74,0x3a,0x9d,0x5d,0x2a,0xa9,0x2c,0x9c,0xfe,0xed,0x72,
0x9d,0xeb,0x5c,0xe7,0x3a,0xd7,0xb9,0x64,0xad,0x88,0xdb,0x2e,0x79,0xf9,0x5e,0x6e,
0xd7,0x76,0xdb,0x76,0x6d,0xb7,0x8c,0x52,0x59,0x9d,0x7d,0xa9,0x2c,0x1f,0x1f,0xa5,
0x73,0xf2,0x55,0xd7,0x75,0xea,0xe5,0xe5,0xdd,0x7e,0xbb,0xd4,0xf9,0x56,0x77,0xa5,
0x5e,0x6d,0xcb,0x29,0xdb,0x9d,0x73,0xce,0x39,0x77,0x56,0x39,0x46,0xbe,0xb7,0xcb,
0xed,0x20,0xb6,0xb2,0xd9,0xec,0x72,0x1b,0xdc,0xae,0x64,0x3a,0x3f,0x99,0x92,0xe9,
0xb4,0x22,0x53,0x32,0x9d,0x8e,0x4e,0xc9,0x74,0x3a,0x3a,0x25,0xd3,0xe9,0xf0,0xb4,
0x54,0x2e,0x5d,0xc9,0x4a,0xe6,0x95,0x1d,0x49,0xe9,0xb4,0x92,0xe9,0xf8,0x96,0xe9,
0xfc,0x48,0x52,0x32,0x9d,0x9f,0x75,0x99,0xce,0x8f,0xa5,0x65,0x3a,0x3f,0x92,0x94,
0x4c,0xc7,0xb7,0x4c,0xe7,0x27,0x53,0x32,0x9d,0x9f,0x2c,0xad,0x64,0x74,0x69,0x25,
0xe3,0x5b,0xa6,0xf3,0x93,0x29,0xf2,0xb4,0x92,0xd1,0x29,0x99,0x4e,0x47,0xa7,0x64,
0x7e,0x99,0x56,0xa4,0x8a,0xdf,0xb9,0x74,0xb4,0xce,0xa5,0xf3,0x8a,0xcb,0xb9,0xce,
0x75,0x3a,0xae,0xce,0x75,0xae,0x73,0x8e,0xab,0x73,0x9d,0xeb,0x9c,0xc3,0xd1,0x56,
0xf9,0x9c,0x73,0x4e,0xe7,0x94,0x1c,0x6b,0x8e,0x5b,0xf9,0x74,0x4e,0x21,0xc9,0xe9,
0x74,0x4e,0x91,0x2a,0x9f,0xce,0x29,0x24,0x39,0x97,0x4e,0x3b,0x1c,0x39,0x9d,0x8e,
0xcb,0xb9,0x74,0xda,0x71,0x39,0x97,0x8e,0x39,0xe7,0x74,0x9c,0x8e,0xd3,0xb9,0x74,
0xda,0x71,0x39,0x9d,0x8e,0x2e,0xe7,0x74,0x5c,0x9d,0xeb,0x5c,0xe7,0x1c,0x97,0xe3,
0x9a,0xcd,0x71,0x5e,0x5c
};
// bytes:373 ratio: 0.364

const PROGMEM uint8_t Splash_mask[] = {
0x7f,0x3f,0x81,0xff,0x1f
};
// bytes:5 ratio: 0.005


// .\diamond-hands.png  width: 128 height: 64
const PROGMEM uint8_t DiamondHands[] = {
0x7f,0x3f,0xa0,0xdd,0x74,0x3a,0xbb,0xac,0x64,0x25,0x2b,0xd7,0xb9,0x4e,0xa5,0x52,
0x9d,0xeb,0x54,0x2a,0x95,0x4a,0xa5,0x52,0xa9,0x54,0xae,0x92,0x95,0xac,0x7c,0x3a,
0x9d,0xce,0xa7,0xf3,0xf9,0x7c,0x3e,0x90,0x5c,0xcb,0xce,0x65,0xb3,0x95,0xfa,0x5c,
0xe7,0x3a,0xd7,0xb9,0xce,0x75,0xae,0xbb,0xba,0x2b,0x55,0x95,0xfb,0x5c,0xe7,0x52,
0xa9,0x54,0x2a,0xd7,0xb9,0x4e,0x56,0x72,0x9d,0xae,0x64,0x25,0x3b,0x95,0xeb,0xa4,
0xb2,0xe9,0x74,0x3a,0xad,0x92,0xa7,0xf2,0x0e,0x45,0x35,0x78,0xa0,0x6c,0x3a,0x5b,
0xb9,0x4e,0xa5,0xb7,0x9d,0x4b,0xa5,0x52,0xb9,0x4a,0xe6,0xd3,0x0a,0x8f,0x59,0x79,
0xa5,0x54,0xa9,0xcf,0x75,0xee,0x72,0x97,0x63,0xb2,0xdb,0xed,0x76,0x5b,0xc9,0x74,
0x3a,0x9d,0x4e,0xa7,0xd3,0xe9,0x74,0x3a,0x9d,0x5e,0x67,0xb7,0xe9,0x74,0xba,0xd5,
0xdd,0x4a,0xa7,0x53,0xa9,0x5c,0x2b,0x95,0xf3,0x6e,0xd9,0xa9,0x5c,0x3e,0xf8,0xdc,
0xfb,0xbb,0x6c,0x36,0x9b,0xee,0xcf,0xe5,0xb3,0x13,0x4d,0x14,0x9f,0x77,0x79,0x27,
0xf3,0xf9,0xf0,0x94,0x6e,0xf7,0xae,0xd2,0xd9,0xda,0x87,0x32,0xe5,0xf7,0xe9,0x7c,
0x3a,0x9d,0x4e,0x67,0xd3,0x39,0xe5,0xb6,0xb9,0x56,0xe7,0x9c,0xcc,0xa7,0xd3,0x69,
0x25,0xb3,0x29,0xc7,0x59,0x17,0x8a,0xe2,0xb7,0xa5,0xab,0xaf,0x57,0xa9,0x54,0x57,
0x57,0xaa,0xb6,0xf9,0xaa,0x55,0x3e,0x9f,0xcf,0x07,0x6f,0xe6,0xd3,0xf9,0x74,0x3a,
0x9d,0xec,0x64,0xa5,0x97,0xb7,0x4b,0x75,0x4e,0xb9,0x6c,0x72,0x99,0x9c,0x3d,0x9d,
0x4f,0xe7,0xd3,0xe9,0x74,0xb2,0x92,0x3b,0xa5,0x56,0x4a,0xa6,0xf3,0xe5,0x54,0x3e,
0x9f,0xce,0xa7,0xb7,0xf9,0x74,0x3a,0x9d,0x4e,0x6f,0xb7,0xcb,0x4a,0x2a,0xb7,0xdc,
0x2e,0x6b,0xd5,0xa5,0x54,0x3a,0x9d,0x4e,0xe7,0xd3,0xe9,0x74,0x36,0x9d,0xce,0x66,
0xe5,0xe9,0xa4,0xf4,0x9d,0xdc,0x65,0xb3,0xb9,0xca,0x55,0xb2,0x92,0x9d,0x4b,0x75,
0x77,0xd5,0xaa,0x77,0x95,0xf6,0x10,0x72,0x3e,0x9d,0x4f,0xe7,0xd3,0xf9,0x74,0x3e,
0x9d,0x4f,0xe7,0xc3,0x53,0xab,0x2b,0xd5,0xc9,0xf8,0x94,0x97,0x7c,0xee,0x95,0x92,
0xeb,0xb4,0x53,0x2f,0x99,0x77,0xbb,0xdd,0xa4,0xdd,0x5f,0xab,0xd0,0xbe,0xec,0x5c,
0x2a,0x95,0xea,0x64,0x55,0x2e,0xd5,0xb9,0xce,0x29,0x97,0x4e,0xa7,0x03,0x4d,0x64,
0x31,0xb8,0xcf,0xe7,0x53,0x6b,0xe5,0x52,0x63,0x48,0x9d,0x5c,0x26,0x57,0xd9,0x6c,
0x36,0x9b,0x0d,0x43,0xca,0xa5,0xd3,0xe9,0x74,0x3a,0x9b,0x4e,0xa7,0xd3,0xd9,0x74,
0x3a,0xd0,0xa7
};
// bytes:419 ratio: 0.409

const PROGMEM uint8_t DiamondHands_mask[] = {
0x7f,0x3f,0x81,0xff,0x1f
};
// bytes:5 ratio: 0.005


