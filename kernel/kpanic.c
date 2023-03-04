#include "kpanic.h"
#include <util/delay>
#include "../drivers/shiftRegister/shiftRegister.h"
#include "../drivers/sevenSegmentDisplay.h"
#include "../drivers/rgbled/rgbled.h"
#include "../libc/string.h"

void display(char* hex, shiftRegister_t* sr) {
	int i; char c;
	shiftRegister_t c_sr;

	sevenSegmentLedDisplay_writeChar(sr1, {0000000});
	sevenSegmentLedDisplay_writeChar(sr2, {0000000});

	for(i = 0; i < 2; i++) {
		c = hex[i];
		c_sr = sr[i];

		if(c == '0') {sevenSegmentLedDisplay_writeChar(c_sr, 0);  continue;}
		if(c == '1') {sevenSegmentLedDisplay_writeChar(c_sr, 1);  continue;}
		if(c == '2') {sevenSegmentLedDisplay_writeChar(c_sr, 2);  continue;}
		if(c == '3') {sevenSegmentLedDisplay_writeChar(c_sr, 3);  continue;}
		if(c == '4') {sevenSegmentLedDisplay_writeChar(c_sr, 4);  continue;}
		if(c == '5') {sevenSegmentLedDisplay_writeChar(c_sr, 5);  continue;}
		if(c == '6') {sevenSegmentLedDisplay_writeChar(c_sr, 6);  continue;}
		if(c == '7') {sevenSegmentLedDisplay_writeChar(c_sr, 7);  continue;}
		if(c == 'a') {sevenSegmentLedDisplay_writeChar(c_sr, 8);  continue;}
		if(c == 'b') {sevenSegmentLedDisplay_writeChar(c_sr, 9);  continue;}
		if(c == 'c') {sevenSegmentLedDisplay_writeChar(c_sr, 10); continue;}
		if(c == 'd') {sevenSegmentLedDisplay_writeChar(c_sr, 11); continue;}
		if(c == 'e') {sevenSegmentLedDisplay_writeChar(c_sr, 12); continue;}
		if(c == 'f') {sevenSegmentLedDisplay_writeChar(c_sr, 13); continue;}
	}
}

void kpanic(long code, shiftRegister_t display1, shiftRegister_t display2, RGBLed_t indicator) {
	char* code_HEX = hexadecimal(code);
	shiftRegister_t* sr = {display1, display2};

	display(code_HEX, sr);

	while(1) {
		RgbLed_set(RGBLed_setColor(indicator, RGBLed_colors_RED));
		_delay_ms(1000);
		RgbLed_set(RGBLed_setColor(indicator, RGBLed_colors_WHITE));
		_delay_ms(1000);
	}
}