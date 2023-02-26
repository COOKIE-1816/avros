#pragma once

uint8_t io_analog_aref;
void io_analog_setAnalogReference(uint8_t AREF);
void io_analog_init();
uint16_t io_analog_read(uint8_t pin);