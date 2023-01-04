#include "gf.h"
#include "numutils.h"

// Add two polynomials over GF(2)
gf_element add(gf_element a, gf_element b) {
    return a ^ b;
}

/* Multiply two numbers in the GF(2^8) finite field defined
 * by the polynomial x^8 + x^4 + x^3 + x + 1 */
gf_element multiply(gf_element a, gf_element b) {
    gf_element p = 0;
    int hi_bit_set;

    for (int counter = 0; counter < 8; counter++) {
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

// Degree of binary polynomial over GF(2)
int degree(gf_element a) {
    if (a == 0)
        return -1;
    else
        return bit_length(a) - 1;
}

gf_element rem(gf_element a, gf_element b) {
    gf_element result = a;

    while (degree(result) >= degree(b)) {
        int power = degree(result) - degree(b);
        result ^= b << power;    // result - b^power
    }

    return result;
}

// Greater common divisor of two polynomial over GF(2)
gf_element gcd(gf_element a, gf_element b)
{
    gf_element p = a;
    gf_element q = b;

    while (b != 0) {
        gf_element r = rem(a, b);
        a = b;
        b = r;
    }

    return a;
}