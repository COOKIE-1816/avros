#include "shiftreg.h"
#include "../../kernel/io.h"

#include <util/delay.h>

using namespace kernel;

typedef struct shiftreg_t {
    uint8_t latch;
    uint8_t storageClock;
    uint8_t serialIn;

    void sendBit(uint8_t VALUE) {
        writePin(this->serialIn, VALUE);

        writePin(this->storageClock, HIGH);
        _delay_ms(20);

        writePin(this->storageClock, LOW);
    }

    void sendData(uint8_t* data) {
        int i;

        for(i = 0; i < 8; i++) {
            this->sendBit(data[i]);
        }

        writePin(this->latch, HIGH);
        _delay_ms(20);

        writePin(this->latch, LOW);
    }
} shiftreg_t;