#pragma once

using gf_element = unsigned int;
using gf32 = unsigned int;


gf_element add(gf_element a, gf_element b);

gf_element multiply(gf_element a, gf_element b, gf_element mod);

gf32 multiply(gf32 a, gf32 b);

gf32 rem(gf32 a, gf32 b);

gf32 gcd(gf32 a, gf32 b);

gf32 exp(gf32 m, int e, gf32 mod);

gf32 inverse(gf32 a, gf32 mod);

void div(gf32 a, gf32 b, gf32& quo, gf32& rem);

int degree(gf32 a);