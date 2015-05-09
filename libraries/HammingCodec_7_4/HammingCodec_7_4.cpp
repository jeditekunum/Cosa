/**
 * @file HammingCodec_7_4.cpp
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2015, Mikael Patel
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
 * This file is part of the Arduino Che Cosa project.
 */

#include "HammingCodec_7_4.hh"

// Encoding table; 4-bit code to 7-bit symbol
const uint8_t HammingCodec_7_4::symbols[16] __PROGMEM = {
  0x70, 0x01, 0x12, 0x63, 0x24, 0x55, 0x46, 0x37,
  0x48, 0x39, 0x2a, 0x5b, 0x1c, 0x6d, 0x7e, 0x0f
};

// Decoding table; 7-bit symbol to 4-bit code (packed table).
const uint8_t HammingCodec_7_4::codes[64] __PROGMEM = {
  0x11, 0x21, 0x41, 0x6f, 0x81, 0xaf, 0xcf, 0xff,
  0x21, 0x22, 0xc5, 0x27, 0xc9, 0x2b, 0xcc, 0xcf,
  0x41, 0xa3, 0x44, 0x47, 0xa9, 0xaa, 0x4d, 0xaf,
  0x09, 0x27, 0x47, 0x77, 0x99, 0xa9, 0xc9, 0xe7,
  0x81, 0x63, 0x65, 0x66, 0x88, 0x8b, 0x8d, 0x6f,
  0x05, 0x2b, 0x55, 0x65, 0x8b, 0xbb, 0xc5, 0xeb,
  0x03, 0x33, 0x4d, 0x63, 0x8d, 0xa3, 0xdd, 0xed,
  0x00, 0x03, 0x05, 0xe7, 0x09, 0xeb, 0xed, 0xee,
};

/*
 * Calculating the start symbol (7-bits per symbol):
 * 0x55, 0x2a => 101.0101, 010.1010 (preamble 7-bit).
 * 0x55, 0x25 => 101.0101, 010.0101 => 010.0101, 101.0101
 *            =>  1.0010, 1101.0101 => 0x12d5
 */
const uint8_t HammingCodec_7_4::preamble[8] __PROGMEM = {
  0x55, 0x2a, 0x55, 0x2a, 0x55, 0x2a, 0x55, 0x25
};