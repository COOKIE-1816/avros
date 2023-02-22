#pragma once

uint8_t ccmbgc_statusPin;
uint8_t ccmbgc_clockPin;
uint8_t ccmbgc_modePin;
uint8_t ccmbgc_colorPin_r;
uint8_t ccmbgc_colorPin_g;
uint8_t ccmbgc_colorPin_b;
uint8_t ccmbgc_initReg;
uint8_t ccmbgc_colSelect;
uint8_t ccmbgc_rowSelect;
uint8_t ccmbgc_vcc;

void ccmbgc_init();
void ccmbgc_setVideoMode(uint8_t isGraphicsMode);
void ccmbgc_clock_tick();
void ccmbgc_wait();
