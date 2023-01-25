#include "numutils.h"


int bit_length(unsigned int a)
{
    int length = 0;

    while (a > 0)
    {
        length++;
        a >>= 1;
    }

    return length;
}

int hamming_norm(unsigned int a)
{
    int result = 0;

    while (a > 0)
    {
        if (a & 1)
            result++;
        a >>= 1;
    }

    return result;
}

int hamming_distance(unsigned int a, unsigned int b)
{
    return hamming_norm(a ^ b);
}

void toggle_bit(unsigned int& a, int bit)
{
    a ^= 1 << bit;
}