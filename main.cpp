#include <iostream>

#include "gf.h"
#include "numutils.h"
#include "format.h"

int main()
{
    gf_element x = 0x21; // x^5 + 1
    gf_element y = 0x83; // x^7 + x + 1

    gf_element z = multiply(x, y, 0x11B); // x*y mod x^8 + x^4 + x^3 + x + 1

    gf_element r = exp(0x2, 11, 0x11B);

    gf_element quo, rem;

    quo_rem(y, x, quo, rem);

    println(quo);
    println(rem);

    println(z);
}