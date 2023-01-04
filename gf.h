#pragma once

using gf_element = unsigned int;


gf_element add(gf_element a, gf_element b);

gf_element multiply(gf_element a, gf_element b);

gf_element multiply(gf_element a, gf_element b, gf_element mod);

gf_element rem(gf_element a, gf_element b);

gf_element gcd(gf_element a, gf_element b);

int degree(gf_element a);