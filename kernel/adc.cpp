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
    
}