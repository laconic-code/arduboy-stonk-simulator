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
#include <stdint.h>

#define DICTIONARY_EOS_IDX              0
#define DICTIONARY_LITERAL_IDX          1
#define DICTIONARY_1C_LITERAL_IDX       2
#define DICTIONARY_1C_START_IDX         3
#define DICTIONARY_2C_START_IDX         29
#define DICTIONARY_3C_START_IDX         180
#define DICTIONARY_1C_START_OFFSET      3
#define DICTIONARY_2C_START_OFFSET      29
#define DICTIONARY_3C_START_OFFSET      331
#define DICTIONARY_ENTRIES              253
#define DICTIONARY_BYTES                559

#ifdef __cplusplus
extern "C" {
#endif

uint8_t const* Dictionary_get();

#ifdef __cplusplus
} // extern "C" {
#endif