#include "string.h"

char* CHAR(int INTEGER) {
    int n = log10(number) + 1; int i;

    char* numberArray = calloc(n, sizeof(char));

    for (i = n - 1; i >= 0; --i, number /= 10) {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

char* hexadecimal(long DECIMAL) {
    /*char* number = CHAR(INTEGER);
    char* outputBuff;*/

    long quotient, remainder;
    char* hexadecimalnum;
    int i, j = 0;

    quotient = DECIMAL;

    while(quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10) {
            hexadecimalnum[j++] = 48 + remainder;
        }
        else {
            hexadecimalnum[j++] = 55 + remainder;
        }

        quotient = quotient / 16;
    }

    return hexadecimalnum;
}