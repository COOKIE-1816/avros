#include "kpanic.h"
#include "../drivers/shiftRegister/shiftRegister.h"
#include "../drivers/rgbled/rgbled.h"
#include "../libc/string.h"

void kpanic(long code, shiftRegister_t display1, shiftRegister_t display2, RGBLed_t indicator) {
	char* code_HEX = hexadecimal(code);
}