#pragma once

#ifndef TEXT_H_   /* Include guard */
#define TEXT_H_

/*
 * text font & scrolling routines
 */

#include "Arduino.h"

const unsigned char charset[] PROGMEM = {
  0x70, 0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0xf0, 0x88, 0x88, 0xf0,
  0x88, 0x88, 0x88, 0xf0, 0x70, 0x88, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70,
  0xf0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0, 0xf8, 0x80, 0x80, 0xf0,
  0x80, 0x80, 0x80, 0xf8, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x80,
  0x70, 0x88, 0x80, 0x80, 0xb8, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0xf8,
  0x88, 0x88, 0x88, 0x88, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70,
  0x38, 0x08, 0x08, 0x08, 0x08, 0x88, 0x88, 0x70, 0x88, 0x90, 0xa0, 0xc0,
  0xc0, 0xa0, 0x90, 0x88, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8,
  0x88, 0xd8, 0xa8, 0xa8, 0xa8, 0xa8, 0x88, 0x88, 0x88, 0x88, 0xc8, 0xa8,
  0x98, 0x88, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70,
  0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x70, 0x88, 0x88, 0x88,
  0x88, 0xa8, 0x90, 0x78, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0xa0, 0x90, 0x88,
  0x70, 0x88, 0x80, 0x70, 0x08, 0x08, 0x88, 0x70, 0xf8, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70,
  0x88, 0x88, 0x88, 0x50, 0x50, 0x50, 0x20, 0x20, 0x88, 0x88, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0x50, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x08, 0x10, 0x20,
  0x40, 0x80, 0x80, 0xf8, 0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78,
  0x80, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x00, 0x00, 0x70, 0x88,
  0x80, 0x80, 0x80, 0x78, 0x08, 0x08, 0x08, 0x78, 0x88, 0x88, 0x88, 0x78,
  0x00, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x80, 0x78, 0x30, 0x48, 0x40, 0xf0,
  0x40, 0x40, 0x40, 0x40, 0x00, 0x78, 0x88, 0x88, 0x78, 0x08, 0x88, 0x70,
  0x80, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x20, 0x00, 0x60, 0x20,
  0x20, 0x20, 0x20, 0x70, 0x08, 0x00, 0x18, 0x08, 0x08, 0x88, 0x88, 0x70,
  0x80, 0x90, 0xa0, 0xc0, 0xc0, 0xa0, 0x90, 0x88, 0x60, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0xf0, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x70, 0x88,
  0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0xf0, 0x88, 0x88, 0xf0, 0x80, 0x80,
  0x00, 0x00, 0x78, 0x88, 0x88, 0x78, 0x08, 0x08, 0x00, 0x00, 0xf0, 0x88,
  0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x70, 0x80, 0xf0, 0x08, 0x88, 0x70,
  0x00, 0x40, 0xf0, 0x40, 0x40, 0x40, 0x48, 0x30, 0x00, 0x00, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20,
  0x00, 0x00, 0x88, 0x88, 0xa8, 0xa8, 0xa8, 0x50, 0x00, 0x00, 0x88, 0x50,
  0x20, 0x50, 0x88, 0x88, 0x00, 0x00, 0x88, 0x88, 0xf8, 0x08, 0x88, 0x70,
  0x00, 0x00, 0xf8, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x18, 0x00, 0x70, 0x88,
  0x88, 0xf8, 0x88, 0x88, 0x70, 0x00, 0x70, 0x88, 0x88, 0xf8, 0x88, 0x88,
  0xf8, 0x00, 0x70, 0x88, 0x88, 0xf8, 0x88, 0x88, 0xe0, 0x00, 0x70, 0x88,
  0x88, 0xf8, 0x88, 0x88, 0x18, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0x80, 0xf8,
  0x70, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x18, 0x00, 0x70, 0x20,
  0x20, 0x20, 0x20, 0x70, 0x18, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70,
  0x70, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0xf8, 0x00, 0x70, 0x88,
  0x88, 0x88, 0x88, 0x70, 0x18, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70,
  0x70, 0x88, 0x88, 0x80, 0x80, 0xa8, 0x70, 0x20, 0x18, 0x00, 0x70, 0x08,
  0x78, 0x88, 0x88, 0x78, 0x70, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78,
  0xf8, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, 0xc0, 0x00, 0x70, 0x08,
  0x78, 0x88, 0x88, 0x78, 0x18, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70,
  0x70, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x30, 0x00, 0x60, 0x20,
  0x20, 0x20, 0x20, 0x70, 0x18, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70,
  0x70, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0xf8, 0x00, 0x70, 0x88,
  0x88, 0x88, 0x88, 0x70, 0x18, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70,
  0x00, 0x00, 0x70, 0x88, 0x80, 0xa0, 0x78, 0x20, 0x70, 0x88, 0x98, 0xa8,
  0xc8, 0x88, 0x88, 0x70, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70,
  0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x70, 0x88, 0x08, 0x30,
  0x08, 0x08, 0x88, 0x70, 0x10, 0x30, 0x50, 0x50, 0x90, 0xf8, 0x10, 0x10,
  0xf8, 0x80, 0x80, 0xf0, 0x08, 0x08, 0x88, 0x70, 0x70, 0x88, 0x80, 0xf0,
  0x88, 0x88, 0x88, 0x70, 0xf8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x40,
  0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0x70, 0x70, 0x88, 0x88, 0x78,
  0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x00, 0x80, 0x70, 0x88, 0x08, 0x10, 0x20, 0x20, 0x00, 0x20,
  0x70, 0x88, 0xb8, 0xa8, 0xa8, 0xb8, 0x80, 0x78, 0x50, 0x50, 0xf8, 0x50,
  0x50, 0xf8, 0x50, 0x50, 0x20, 0x70, 0x80, 0x70, 0x08, 0x88, 0x70, 0x20,
  0x00, 0xc0, 0xc8, 0x10, 0x20, 0x40, 0x98, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

const char charmap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzÁÂÃÀÉÊÍÓÔÕÚÇáâãàéêíóôõúç0123456789.,!?@#$% ";

void initializeText();
void runText();

#endif // TEXT_H_