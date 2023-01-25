#include <iostream>

#include "gf.h"
#include "numutils.h"
#include "format.h"
#include "cyclic_ecc.h"

int main()
{
    gf32 message = 0x0B; // x^3 + x + 1 = (1011)
    gf32 encoded = encode(message);
    gf32 decoded = decode(encoded);

    println(encoded);
    println(decoded);

    toggle_bit(encoded, 5);

    decoded = decode(encoded);
    println(decoded);
}