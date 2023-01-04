#include "numutils.h"


int bit_length(unsigned int a) {
    int length = 0;

    while (a > 0) {
        length++;
        a >>= 1;
    }

    return length;
}