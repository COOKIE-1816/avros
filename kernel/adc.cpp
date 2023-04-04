#include "adc.h"
#include <avr/io.h>

void kernel::adc::adc_referenceVoltage(char v) {
    switch(v) {
        case 1:
            ADMUX &= ~(1 << REFS0) & ~(1 << REFS1);
            break;
        
        case 2:
            ADMUX |=  (1 << REFS0);
            ADMUX &= ~(1 << REFS1);

            break;
        
        case 3:
            ADMUX |= (1 << REFS0) | (1 << REFS1);


        default:
            ADMUX |= (1 << REFS0);
            ADMUX &= ~(1 << REFS1);
            
            break;
    }
}

void kernel::adc::adc_selectAdcChannel(char channel) {
    switch(channel) {
        case 0:
            ADMUX &= ~(1 << MUX0) & ~(1 << MUX1) & ~(1 << MUX2) & ~(1 << MUX3);
            break;
        
        case 1:
            ADMUX &= ~(1 << MUX1) & ~(1 << MUX2) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX0);

            break;
        
        case 2:
            ADMUX &= ~(1 << MUX0) & ~(1 << MUX2) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX1);

            break;
        
        case 3:
            ADMUX &= ~(1 << MUX2) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX0) |  (1 << MUX1);

            break;
        
        case 4:
            ADMUX &= ~(1 << MUX0) & ~(1 << MUX1) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX2);

            break;
        
        case 5:
            ADMUX &= ~(1 << MUX1) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX0) |  (1 << MUX2);

            break;

        case 6:
            ADMUX &= ~(1 << MUX0) & ~(1 << MUX3);
            ADMUX |=  (1 << MUX1) |  (1 << MUX2);

            break;
        
        case 7:
            ADMUX &= ~(1 << MUX3);
            ADMUX |=  (1 << MUX0) | (1 << MUX1) | (1 << MUX2);

            break;
    }
}

void kernel::adc::adc_enable() {
    ADCSRA |= (1 << ADEN);
}

void kernel::adc::adc_disable() {
    ADCSRA &= ~(1 << ADEN);
}

uint16_t kernel::adc::adc_measure() {
    ADCSRA |= (1 << ADSC);
    while(ADCSRA & (1 << ADSC));

    return ADC;
}

float kernel::adc::adc_toVoltage(uint16_t value, float reference) {
    return reference * (value / 1023.0);
}

void kernel::adc::adc_init(uint8_t division, char reference, char channel) {
    switch(division) {
        case 2:
            ADCSRA &= ~(1 << ADPS0) | ~(1 << ADPS1) | ~(1 << ADPS2);
            
            break;

        case 4:
            ADCSRA &= ~(1 << ADPS0) | ~(1 << ADPS2);
            ADCSRA |=  (1 << ADPS1);

            break;

        case 8:
            ADCSRA &= ~(1 << ADPS2);
            ADCSRA |=  (1 << ADPS0) | (1 << ADPS1);

            break;

        case 16:
            ADCSRA &= ~(1 << ADPS0) | ~(1 << ADPS1);
            ADCSRA |=  (1 << ADPS2);

            break;

        case 32:
            ADCSRA &= ~(1 << ADPS1);
            ADCSRA |=  (1 << ADPS0) | (1 << ADPS2);

            break;

        case 64:
            ADCSRA &= ~(1 << ADPS0);
            ADCSRA |=  (1 << ADPS1) | (1 << ADPS2);

            break;

        case 128:
            ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);

            break;
    }

    kernel::adc::adc_referenceVoltage(reference);
    kernel::adc::adc_selectAdcChannel(channel);
    
    kernel::adc::adc_enable();
}