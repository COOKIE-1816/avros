#pragma once
#include <stdint.h>

uint8_t masks[23];
enum kernel_io_modes {
    kernel_io_modes_IN,
    kernel_io_modes_OUT
};


void io_mode(uint8_t pin, enum kernel_io_modes MODE);
void io_init();
