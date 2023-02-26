#include "analog.h"
#include "io.h"
#include "avr/io.h"

uint8_t io_analog_setAnalogReference(uint8_t AREF) {

}

void io_analog_init() {
	TCCR0 |= (1 << CS01);
	TCCR0 |= (1 << WGM01) | (1 << WGM00);
	TCCR0 |= (1 << COM01);
}

uint16_t io_analog_read(uint8_t pin) {
	uint8_t mask = masks[pin];

	ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((mask >> 3) & 0x01) << MUX5);

}