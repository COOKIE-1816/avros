#include <avr/io.h>
#include "./kernel/io/io.h"
#include "./kernel/io/digital.h"

#define POWERBUTTON 4

void standby() {
    io_init();
    while(1) {
        if(io_digital_read(POWERBUTTON) == HIGH) {
            return;
        }
    }
};

void kmain() {
    io_init();
}

int main(void) {
    kmain();
    standby();

    return 0;
}
