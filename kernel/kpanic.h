#pragma once
#include "../drivers/shiftRegister/shiftRegister.h"
#include "../drivers/rgbled/rgbled.h"

void kpanic(int code, shiftRegister_t display1, shiftRegister_t display2, RGBLed_t indicator);