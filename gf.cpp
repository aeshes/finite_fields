#include "gf.h"
#include "numutils.h"

// Add two polynomials over GF(2)
gf_element add(gf_element a, gf_element b) {
    return a ^ b;
}

// Multiply two numbers in the GF(2^8) finite field defined by the polynomial
gf_element multiply(gf_element a, gf_element b, gf_element mod) {
    gf_element result = 0;

    a = rem(a, mod);
    b = rem(b, mod);
    
    int d = degree(mod);

    while (a != 0) {
        if (a & 1)
            result ^= b;
        a >>= 1;
        b <<= 1;

        if (degree(b) == d)
            b ^= mod;
    }

    return result;
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
        result ^= b << power; // result - b*x^power
    }

    return result;
}

void quo_rem(polynomial a, polynomial b, polynomial& quo, polynomial& rem) {
    rem = a;
    quo = 0;

    while (degree(rem) >= degree(b)) {
        int power = degree(rem) - degree(b);
        rem ^= b << power; // rem - b*x^power
        quo ^= 1 << power; // quo + x^power
    }
}

// Greater common divisor of two polynomials over GF(2)
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

// Calculates m^e mod n
gf_element exp(gf_element m, gf_element e, gf_element mod)
{
    gf_element result = 1;

    while (e != 0)
    {
        // multiplying
        if (e & 0x1)
            result = multiply(result, m, mod);

        // squaring
        m = multiply(m, m, mod);
        e >>= 1;
    }

    return result;
}