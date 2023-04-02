#include "kpanic.h"
#include "../drivers/indicator/indicator.h"
#include <util/delay.h>

void kernel::panic() {
    indicator_green_set(0x00);
    indicator_yellow_set(0x00);

    while(1) {
        indicator_red_set(0xFF);
        _delay_ms(200);
        indicator_red_set(0x00);
        _delay_ms(200);
    }
}