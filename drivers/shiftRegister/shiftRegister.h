#pragma once

typedef struct shiftRegister_t {
    uint8_t serial_out;
    uint8_t serial_in;
    uint8_t mr;
    uint8_t shiftRegister_clock;
    uint8_t storageRegister_clock;
};

void shiftRegister_sendBit(shiftRegister_t shiftRegister, uint8_t data);
void shiftRegister_write(shiftRegister_t shiftRegister);
