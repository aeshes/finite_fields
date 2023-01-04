#include "numutils.h"


int bit_length(uint8_t a) {
    int length = 0;

    while (a > 0) {
        length++;
        a >>= 1;
    }

    return length;
}

// Degree of binary polynomial over GF(2)
int degree(uint8_t a) {
    if (a == 0)
        return -1;
    else
        return bit_length(a) - 1;
}