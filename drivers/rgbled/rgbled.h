#pragma once

typedef struct RGBLed_t {
    uint8_t pinout_r;
    uint8_t pinout_g;
    uint8_t pinout_b;

    uint8_t r;
    uint8_t g;
    uint8_t b;
};

enum RGBLed_colors {
    RGBLed_colors_RED[],
    RGBLed_colors_GREEN[],
    RGBLed_colors_BLUE[],
    RGBLed_colors_YELLOW[],
    RGBLed_colors_PURPLE[],
    RGBLed_colors_WHITE[],
};

RGBLed_t RGBLed_setColor(RGBLed_t RGBLed_Struct, enum RGBLed_colors color);
void RGBLed_set(RGBLed_t RGBLed_Struct);
