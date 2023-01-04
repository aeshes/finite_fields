#include <iostream>

#include "gf.h"
#include "numutils.h"

int main()
{
    gf_element x = 0x21; // x^5 + 1
    gf_element y = 0x83; // x^7 + x + 1

    gf_element z = multiply(x, y);

    int length = bit_length(z);

    gf_element t = rem(x, y);
    gf_element s = rem(y, x);

    std::cout << std::hex << z;
}