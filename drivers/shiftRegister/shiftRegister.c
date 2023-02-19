#include <util/delay.h>
#include "shiftRegister.h"
#include "/kernel/io/digital.h"

typedef struct shiftRegister_t {
    uint8_t serial_out;
    uint8_t serial_in;
    uint8_t mr;
    uint8_t shiftRegister_clock;
    uint8_t storageRegister_clock;
};

void shiftRegister_tick(shiftRegister_t shiftRegister) {
    io_digital_write(shiftRegister.shiftRegister_clock, 0xFF);
    _delay_ms(5);
    io_digital_write(shiftRegister.shiftRegister_clock, 0x00);
    _delay_ms(5);
}

void shiftRegister_latchTick(shiftRegister_t shiftRegister) {
    io_digital_write(shiftRegister.storageRegister_clock, 0xFF);
    _delay_ms(5);
    io_digital_write(shiftRegister.storageRegister_clock, 0x00);
    _delay_ms(5);
}

void shiftRegister_sendBit(shiftRegister_t shiftRegister, uint8_t data) {
    io_digital_write(shiftRegister.serial_in, data);
    shiftRegister_tick();
}

void shiftRegister_write(shiftRegister_t shiftRegister, uint8_t* data) {
    for(int i = 0; i < 8; i = i + 1) {
        shiftRegister_sendBit(shiftRegister, data[i]);
    }

    shiftRegister_latchTick(shiftRegister);
}
