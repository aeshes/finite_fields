#include <cstdio>

#include "format.h"
#include "numutils.h"

void println(gf_element e)
{
    for (int bit = bit_length(e) - 1; bit >= 0; bit--)
    {
        printf("%d", (e >> bit) & 1);
    }
    printf("\n");
}