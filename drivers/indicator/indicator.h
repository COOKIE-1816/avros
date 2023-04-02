#pragma once
#include <stdint.h>

#define INDICATOR_RED 0
#define INDICATOR_YELLOW 1
#define INDICATOR_GREEN 2

void indicator_red_set(uint8_t b);
void indicator_yellow_set(uint8_t b);
void indicator_green_set(uint8_t b);

//void indicator_blink(uint8_t r, uint8_t y, uint8_t g, int interval, int duration /*0 for infinity*/);