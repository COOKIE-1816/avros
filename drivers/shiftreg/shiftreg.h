#pragma once
#include <stdint.h>

typedef struct shiftreg_t {
    uint8_t latch;
    uint8_t storageClock;
    uint8_t serialIn;

    void sendBit(uint8_t VALUE);
    void sendData(uint8_t* data);
} shiftreg_t;