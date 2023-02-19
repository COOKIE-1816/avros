#pragma once
#include "/drivers/shiftRegister/shiftRegister.h"

uint8_t sevenSegmentLedDisplay_chars[16][7];
void sevenSegmentLedDisplay_writeChar(shiftRegister_t shiftRegister, uint8_t CHARACTER[7], uint8_t DOT]);
