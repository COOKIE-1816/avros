#pragma once
#include <stdint.h>

#define PORT_B 0
#define PORT_C 1
#define PORT_D 2

#define LOW 0x00
#define HIGH 0xFF

namespace kernel {
    /*static uint8_t low;
    static uint8_t high;*/

    uint8_t readPB(uint8_t PIN);
    uint8_t readPC(uint8_t PIN);
    uint8_t readPD(uint8_t PIN);

    void writePB0(uint8_t PIN);
    void writePC0(uint8_t PIN);
    void writePD0(uint8_t PIN);

    void writePB1(uint8_t PIN);
    void writePC1(uint8_t PIN);
    void writePD1(uint8_t PIN);

    uint8_t readPin(uint8_t PIN);
    void writePin(uint8_t PIN, uint8_t VALUE);
    
    uint8_t getPinNumber(int port, uint8_t pin);
    int getPort(int pin);
};

