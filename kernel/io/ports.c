#include "ports.h"
#include <avr/io.h>

uint8_t port_masks[3] = {
    PORTB, PORTC, PORTD
};

uint8_t pinToPort[23] = {
    0x01, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x00, 0x00,
    0x02, 0x02, 0x02, 0x00,
    0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00
};

uint8_t PORT(uint8_t pin) {
    return port_masks[pinToPort[pin]];
};
