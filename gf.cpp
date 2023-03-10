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

gf32 multiply(gf32 a, gf32 b)
{
    gf32 result = 0;

    while (a != 0)
    {
        if (a & 1)
            result ^= b;
        a >>= 1;
        b <<= 1;
    }

    return result;
}

// Degree of binary polynomial over GF(2)
int degree(gf32 a) {
    if (a == 0)
        return -1;
    else
        return bit_length(a) - 1;
}

gf32 rem(gf32 a, gf32 b) {
    gf32 result = a;

    while (degree(result) >= degree(b)) {
        int power = degree(result) - degree(b);
        result ^= b << power; // result - b*x^power
    }

    return result;
}

void div(gf32 a, gf32 b, gf32& quo, gf32& rem) {
    rem = a;
    quo = 0;

    while (degree(rem) >= degree(b)) {
        int power = degree(rem) - degree(b);
        rem ^= b << power; // rem - b*x^power
        quo ^= 1 << power; // quo + x^power
    }
}

// Greater common divisor of two polynomials over GF(2)
gf32 gcd(gf32 a, gf32 b)
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

void xgcd(gf32 a, gf32 b, gf32& gcd, gf32& x, gf32& y)
{
    if (b == 0)
    {
        gcd = a;
        x = 1;
        y = 0;
    }
    else
    {
        gf32 quo, rem = 0;
        gf32 d, x1, y1 = 0;

        div(a, b, quo, rem);
        xgcd(b, rem, d, x1, y1);

        x = y1;
        y = add(x1, multiply(y1, quo));
    }
}

gf32 inverse(gf32 a, gf32 mod)
{
    gf32 gcd, x, y = 0;

    xgcd(a, mod, gcd, x, y);

    return rem(x, mod);
}

// Calculates m^e mod n
gf32 exp(gf32 m, int e, gf32 mod)
{
    gf32 result = 1;

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