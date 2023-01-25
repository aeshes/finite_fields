#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>

#include "gf.h"
#include "numutils.h"
#include "format.h"
#include "cyclic_ecc.h"

int main()
{
    std::map<unsigned char, unsigned int> codec;

    for (unsigned char c = 0; c <= 15; c++)
    {
        codec[c] = encode(c);
    }

    std::cout << "Encoded messages: " << std::endl;
    for (auto it : codec)
    {
        std::bitset<7> message(it.first), codeword(it.second);

        std::cout << message << " -> " << codeword << std::endl;
    }

    std::cout << "Decoded messages: " << std::endl;
    for (auto it : codec)
    {
        std::bitset<7> codeword(it.second), message(decode(it.second));

        std::cout << codeword << " -> " << message << std::endl;
    }
}