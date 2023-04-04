#include "math.h"

float sqrt(int x) {
    float SQRT, TMP;

    SQRT = x / 2;
    TMP = 0;

    while(SQRT != TMP) {
        TMP = SQRT;
        SQRT = (x / TMP + TMP) / 2;
    }

    return SQRT;
}