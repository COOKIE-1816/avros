#include "kernel.h"

void kernel::Sleep::addWakeEvent(uint8_t func, uint8_t requiredValue) {
    int x = kernel::Sleep::wakeEventList_length + 1;

    kernel::Sleep::wakeEventList[x];
    kernel::Sleep::wakeEventList_requiredValues[x];

    kernel::Sleep::wakeEventList_length++;
}

