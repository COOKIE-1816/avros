#include "io.h"
#include <avr/io.h>

#define LOW 0x00
#define HIGH 0xFF

namespace kernel {
    uint8_t readPB(uint8_t PIN) {
        return (PINB & (1 << PIN));
    }

    uint8_t readPC(uint8_t PIN) {
        return (PINC & (1 << PIN));
    }

    uint8_t readPD(uint8_t PIN) {
        return (PIND & (1 << PIN));
    }

    uint8_t readPin(uint8_t PIN) {
        int port = getPort(PIN);

        if(port == 0) {
            return readPB(getPinNumber(0, PIN));
        }

        if(port == 1) {
            return readPC(getPinNumber(1, PIN));;
        }

        if(port == 2) {
            return readPD(getPinNumber(2, PIN));
        }
    }

    void writePB0(uint8_t PIN) {
        PINB |= (1 << PIN);
    }

    void writePC0(uint8_t PIN) {
        PINC |= (1 << PIN);
    }

    void writePD0(uint8_t PIN) {
        PIND |= (1 << PIN);
    }


    void writePB1(uint8_t PIN) {
        PINB &= ~(1 << PIN);
    }

    void writePC1(uint8_t PIN) {
        PINC &= ~(1 << PIN);
    }

    void writePD1(uint8_t PIN) {
        PIND &= ~(1 << PIN);
    }

    void writePin(uint8_t PIN, uint8_t VALUE) {
        int PORT = getPort(PIN);
        
        PIN = getPinNumber(PORT, PIN);

        if(PORT == 0 && VALUE == 0x00) {kernel::writePB0(PIN);}
        if(PORT == 1 && VALUE == 0x00) {kernel::writePC0(PIN);}
        if(PORT == 2 && VALUE == 0x00) {kernel::writePD0(PIN);}
        if(PORT == 0 && VALUE == 0xFF) {kernel::writePB1(PIN);}
        if(PORT == 1 && VALUE == 0xFF) {kernel::writePC1(PIN);}
        if(PORT == 2 && VALUE == 0xFF) {kernel::writePD1(PIN);}
    }


    uint8_t getPinNumber(int port, uint8_t pin) {
        if(port == 1) {
            pin = pin - 8;
        }

        if(port == 2) {
            pin = pin - (8 + 7);
        }

        return pin;
    }

    int getPort(int pin) {
        if(pin < 8) {return 0;}
        if(pin < 15) {return 1;}
        return 2;
    }
};