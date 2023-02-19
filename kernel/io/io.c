#include "io.h"
#include "ports.h"

#include </avr/io.h>

uint8_t masks [] = {
    DDC6, DDD0, DDD1, DDD2,
    DDD3, DDD4, DDB6, DDB7,
    DDD5, DDD6, DDD7, DDB0,
    DDC5, DDC4, DDC3, DDC2,
    DDC1, DDC0, DDB5, DDB4,
    DDB3, DDB2, DDB1,
};

enum kernel_io_modes {
    kernel_io_modes_IN = 0x00,
    kernel_io_modes_OUT = 0xFF
};

void io_mode(uint8_t pin, enum kernel_io_modes MODE) {
    uint8_t port = PORT(pin);
    uint8_t mask = masks[pin];

    if(MODE != kernel_io_modes_IN && MODE != kernel_io_modes_OUT) {
        // Unsupported direction
        io_mode(pin, kernel_io_modes_OUT);
        return;
    }

    if(MODE == kernel_io_modes_IN) {
        // Input
        switch(port) {
            case PORTB: DDRB |= (1 << mask); return;
            case PORTC: DDRC |= (1 << mask); return;
            case PORTD: DDRD |= (1 << mask); return;

            default: return;
        }

    }

    // Output
    switch(port) {
        case PORTB: DDRB &= ~(1 << mask); return;
        case PORTC: DDRC &= ~(1 << mask); return;
        case PORTD: DDRD &= ~(1 << mask); return;

        default: return;
    }
};


void io_init() {
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
}
