#include "digital.h"
#include "ports.h"
#include "io.h"

uint8_t HIGH = 0xFF;
uint8_t LOW = 0x00;

void io_digital_write(uint8_t pin, uint8_t val) {
    uint8_t port = PORT(pin);
    uint8_t mask = masks[pin];

    if(val == HIGH) {
        // HIGH (0xFF)
        switch(port) {
            case PORTB: PORTB |= (1 << mask); return;
            case PORTC: PORTC |= (1 << mask); return;
            case PORTD: PORTD |= (1 << mask); return;

            default: return;
        }
    }

    // LOW (0x00)
    switch(port) {
        case PORTB: PORTB &= ~(1 << mask); return;
        case PORTC: PORTC &= ~(1 << mask); return;
        case PORTD: PORTD &= ~(1 << mask); return;

        default: return;
    }
}

uint8_t io_digital_read(uint8_t pin) {
    uint8_t port = PORT(pin);
    uint8_t mask = masks[pin];

    uint8_t val;

    switch(port) {
        case PORTB: val = PINB & (1 << mask); return;
        case PORTC: val = PINC & (1 << mask); return;
        case PORTD: val = PIND & (1 << mask); return;

        default: return;
    }

    if(val) {
        return HIGH;
    }

    return LOW;
}
