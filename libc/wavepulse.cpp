#include "wavepulse.h"
#include "../kernel/io.h"
#include <util/delay.h>

using namespace kernel;
//using namespace wavePulse;

typedef struct wavePulse::squareWave {
    double low_duration;
    double high_duration;
    /*uint8_t max;
    uint8_t min;*/

    void generate(uint8_t pin, int loopCount) {
        int i;

        for(i = 0; i < loopCount; i++) {
            writePin(pin, LOW);
            _delay_ms(this->low_duration);

            writePin(pin, HIGH);
            _delay_ms(this->high_duration);
        }
    }
} squareWave;