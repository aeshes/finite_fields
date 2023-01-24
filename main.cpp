#include <iostream>

#include "gf.h"
#include "numutils.h"
#include "format.h"
#include "cyclic_ecc.h"

int main()
{
    gf_element x = 0x21;    // x^5 + 1
    gf_element y = 0x83;    // x^7 + x + 1
    gf_element mod = 0x11B; // x^8 + x^4 + x^3 + x + 1

    polynomial message = 0x0F; // x^3 + x^2 + x + 1 = (1111)
    polynomial encoded = encode(message);
    println(encoded);
}