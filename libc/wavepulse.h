#pragma once
#include <stdint.h>

namespace wavePulse {
    typedef struct squareWave {
        int low_duration;
        int high_duration;
        uint8_t max;
        uint8_t min;

        void generate(uint8_t pin, int loopCount);
    } squareWave;
}