#pragma once

uint8_t HIGH;
uint8_t LOW;

void io_digital_write(uint8_t pin, uint8_t val);
uint8_t io_digital_read(uint8_t pin);
