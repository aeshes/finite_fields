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

    gf32 message = 0x0F; // x^3 + x^2 + x + 1 = (1111)
    gf32 encoded = encode(message);
    gf32 decoded = decode(encoded);

    println(encoded);
    println(decoded);

    toggle_bit(encoded, 3);
    println(encoded);

    decoded = decode(encoded);
    println(decoded);
}