#pragma once
#include "../shiftreg/shiftreg.h"

uint8_t** ssdisplay_chars = {
    {0xFF, 0xFF, 0xFF, 0xFF}
}

typedef struct ssdisplay_t {
    shiftreg_t sreg;


} ssdisplay_t;