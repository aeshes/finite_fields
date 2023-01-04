#include <cstdint>
#include <iostream>

#include "numutils.h"


// Add two polynomials over GF(2)
uint8_t gadd(uint8_t a, uint8_t b) {
    return a ^ b;
}

/* Multiply two numbers in the GF(2^8) finite field defined
 * by the polynomial x^8 + x^4 + x^3 + x + 1 */
uint8_t gmul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    uint8_t counter;
    uint8_t hi_bit_set;

    for (counter = 0; counter < 8; counter++) {
        if (b & 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set)
            a ^= 0x1b; /* x^8 + x^4 + x^3 + x + 1 */
        b >>= 1;
    }

    return p;
}

uint8_t rem(uint8_t a, uint8_t b) {
    uint8_t result = a;

    while (degree(result) >= degree(b)) {
        int position = degree(result) - degree(b);
        result ^= b << position;
    }

    return result;
}

// Greater common divisor of two polynomial over GF(2)
uint8_t gcd(uint8_t a, uint8_t b)
{
    uint8_t p = a;
    uint8_t q = b;

    while (b != 0) {
        uint8_t r = rem(a, b);
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    uint8_t x = 0x21; // x^5 + 1
    uint8_t y = 0x83; // x^7 + x + 1

    uint8_t z = gmul(x, y);

    int length = bit_length(z);

    std::cout << std::hex << z;
}