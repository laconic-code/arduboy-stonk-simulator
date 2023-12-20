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
#include <limits.h>

template <typename T>
struct Limit {
  static constexpr bool is_signed = false;
  static constexpr T maxVal() noexcept { return T(); }
  static constexpr T minVal() noexcept { return T(); }
};

#define X(TYPE, MIN, MAX, SIGNED, INTEGER) \
  template <> \
  struct Limit<TYPE> { \
    static constexpr bool is_signed = SIGNED; \
    static constexpr bool is_integer = INTEGER; \
    static constexpr TYPE maxVal() noexcept { return MAX; } \
    static constexpr TYPE minVal() noexcept { return MIN; } \
  }
  X(uint8_t, 0, UINT8_MAX, false, true);
  X(uint16_t, 0, UINT16_MAX, false, true);
  X(uint32_t, 0, UINT32_MAX, false, true);
  X(uint64_t, 0, UINT64_MAX, false, true);
  X(int8_t, INT8_MIN, INT8_MAX, true, true);
  X(int16_t, INT16_MIN, INT16_MAX, true, true);
  X(int32_t, INT32_MIN, INT32_MAX, true, true);
  X(int64_t, INT64_MIN, INT64_MAX, true, true);
#undef X

template <typename T>
inline T clamp(
    T const& val,
    T const& min = Limit<T>::minVal(),
    T const& max = Limit<T>::maxVal()) {
  if (val < min) {
    return min;
  } else if (val > max) {
    return max;
  } else {
    return val;
  }
}

template <typename T>
inline T addClamp(
    T a,
    T b,
    T const& tFloor = Limit<T>::minVal(),
    T const& tCeiling = Limit<T>::maxVal()) {
  constexpr T ZERO = 0;
  if (a < b) {
    // smaller term always in b
    T c = a;
    a = b;
    b = c;
  }

  if (a > ZERO && b > ZERO) {
    return (a < (tCeiling - b)) ? a + b : tCeiling;
  } else if (a < ZERO && b < ZERO) {
    return (a > (tFloor - b)) ? a + b : tFloor;
  } else {
    // a is positive, b is negative
    return (a > (tFloor - b)) ? a + b : tFloor;
  }
}

template <typename T>
inline T subClamp(
    T const& a,
    T const& b,
    T const& tFloor = Limit<T>::minVal(),
    T const& tCeiling = Limit<T>::maxVal()) {
  return addClamp<T>(a, -b, tFloor, tCeiling);
}
