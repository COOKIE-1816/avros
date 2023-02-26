#include "ccmbgc.h"
#include "kernel/io/io.h"
#include "kernel/io/digital.h"

void ccmbgc_wait() {
    while(io_digital_read(ccmbgc_statusPin) == HIGH);
}

void ccmbgc_clock_tick() {
    io_digital_write(ccmbgc_clockPin, HIGH);
    ccmbgc_wait();
    io_digital_write(ccmbgc_clockPin, LOW);
}


void ccmbgc_setVideoMode(uint8_t isGraphicsMode) {
    io_digital_write(ccmbgc_modePin, isGraphicsMode);
    ccmbgc_clock_tick();
}


void ccmbgc_init(int COL, int ROW) {
    io_init();

    io_mode(ccmbgc_statusPin,   kernel_io_modes_IN);
    io_mode(ccmbgc_clockPin,    kernel_io_modes_OUT);
    io_mode(ccmbgc_modePin,     kernel_io_modes_OUT);
    io_mode(ccmbgc_clockPin,    kernel_io_modes_OUT);
    io_mode(ccmbgc_colorPin_r,  kernel_io_modes_OUT);
    io_mode(ccmbgc_colorPin_g,  kernel_io_modes_OUT);
    io_mode(ccmbgc_colorPin_b,  kernel_io_modes_OUT);
    io_mode(ccmbgc_initRegister,kernel_io_modes_OUT);
    io_mode(ccmbgc_colSelect,   kernel_io_modes_OUT);
    io_mode(ccmbgc_rowSelect,   kernel_io_modes_OUT);
    io_mode(ccmbgc_vcc,         kernel_io_modes_OUT);

    io_digital_write(ccmbgc_vcc, HIGH);
    io_digital_write(ccmbgc_initRegister, HIGH);
    ccmbgc_wait();

    io_digital_write(ccmbgc_colSelect, HIGH);
    for(int i = 0; i < COL / 5; i++) {
        ccmbgc_clock_tick();
    }

    io_digital_write(ccmbgc_colSelect, LOW);

    io_digital_write(ccmbgc_rowSelect, HIGH);
    for(int i = 0; i < ROW / 5; i++) {
        ccmbgc_clock_tick();
    }

    io_digital_write(ccmbgc_rowSelect, LOW);

    ccmbgc_setVideoMode(0x00);
}
