#include <iostream>

#include "gf.h"
#include "numutils.h"

int main()
{
    gf_element x = 0x21; // x^5 + 1
    gf_element y = 0x83; // x^7 + x + 1

    gf_element z = multiply(x, y, 0x11B); // x*y mod x^8 + x^4 + x^3 + x + 1

    int length = bit_length(z);

    gf_element t = rem(x, y);
    gf_element s = rem(y, x);

    gf_element r = exp(0x2, 11, 0x11B);

    std::cout << std::hex << z;
}