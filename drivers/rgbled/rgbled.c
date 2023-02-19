#include "rgbled.h"
#include "/kernel/io/digital.h"

typedef struct RGBLed_t {
    uint8_t pinout_r;
    uint8_t pinout_g;
    uint8_t pinout_b;

    uint8_t r;
    uint8_t g;
    uint8_t b;
};

enum RGBLed_colors {
    //            COLOR       R     G     B
    //=========================================
    RGBLed_colors_RED[]    = {0xFF, 0x00, 0x00},
    RGBLed_colors_GREEN[]  = {0x00, 0xFF, 0x00},
    RGBLed_colors_BLUE[]   = {0x00, 0x00, 0xFF},
    RGBLed_colors_YELLOW[] = {0xFF, 0xFF, 0x00},
    RGBLed_colors_PURPLE[] = {0x00, 0xFF, 0xFF},
    RGBLed_colors_WHITE[]  = {0xFF, 0xFF, 0xFF},
};

RGBLed_t RGBLed_setColor(RGBLed_t RGBLed_Struct, enum RGBLed_colors color) {
    RGBLed_Struct.r = color[0];
    RGBLed_Struct.g = color[1];
    RGBLed_Struct.b = color[2];

    return RGBLed_Struct;
}

void RGBLed_set(RGBLed_t RGBLed_Struct) {
    io_digital_write(RGBLed_Struct.pinout_r, RGBLed_Struct.r); // R
    io_digital_write(RGBLed_Struct.pinout_g, RGBLed_Struct.g); // G
    io_digital_write(RGBLed_Struct.pinout_b, RGBLed_Struct.b); // B
}
