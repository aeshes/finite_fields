#include <iostream>

#include "gf.h"
#include "numutils.h"
#include "format.h"

int main()
{
    gf_element x = 0x21;    // x^5 + 1
    gf_element y = 0x83;    // x^7 + x + 1
    gf_element mod = 0x11B; // x^8 + x^4 + x^3 + x + 1

    gf_element z = multiply(x, y, mod); 

    println(multiply(x, y));

    polynomial inv = inverse(y, mod);
    println(inv);
    println(multiply(inv, y, mod));

    println(z);
}