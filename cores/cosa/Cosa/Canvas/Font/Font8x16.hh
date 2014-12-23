/**
 * @file Font8x16.hh
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2014, jediunix
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 */

#ifndef COSA_FONT_FONT8X16_HH
#define COSA_FONT_FONT8X16_HH

#include "Cosa/Canvas/Font.hh"

/**
 * Font size 8x16.
 */
class Font8x16 : public Font {
public:
  /**
   * Construct font (8x16) singleton.
   */
  Font8x16() :
    Font(width, height, first, last, bitmap)
  {}

private:
  static const uint8_t bitmap[] PROGMEM;
  static const uint8_t width;
  static const uint8_t height;
  static const uint8_t first;
  static const uint8_t last;
};

extern Font8x16 font8x16;

#endif
