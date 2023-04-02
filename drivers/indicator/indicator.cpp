#include "indicator.h"
#include <util/delay.h>
#include "../../kernel/io.h"

using namespace kernel;

void indicator_red_set(uint8_t b) {
    writePin(INDICATOR_RED, b);
}

void indicator_yellow_set(uint8_t b) {
    writePin(INDICATOR_YELLOW, b);
}

void indicator_green_set(uint8_t b) {
    writePin(INDICATOR_GREEN, b);
}

/*void indicator_blink(uint8_t r, uint8_t y, uint8_t g, int interval, int duration) {
    DigitalIo dio;
    uint8_t b2 = LOW;
    int blink_length = duration / interval;

    indicator_red_set(LOW);
    indicator_yellow_set(LOW);
    indicator_green_set(LOW);

    for(int i = 0; i < )
}*/