#pragma once
/*#ifndef F_CPU
    #define F_CPU 16000000UL
#endif*/
/*
#ifndef ADC_H_
#define ADC_H_
*/

#define AREF 1
#define AVCC 2
#define INTERNAL 3
#include <stdint.h>

namespace kernel {
    namespace adc {
        void adc_referenceVoltage(char v);
        void adc_selectAdcChannel(char channel);
        void adc_enable();
        void adc_disable();
        uint16_t adc_measure();
        float adc_toVoltage(uint16_t value, float reference);
        void adc_init(uint8_t division, char reference, char channel);
    };
};

//#endif