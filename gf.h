#pragma once

using gf_element = unsigned int;
using polynomial = unsigned int;


gf_element add(gf_element a, gf_element b);

gf_element multiply(gf_element a, gf_element b, gf_element mod);

gf_element rem(gf_element a, gf_element b);

gf_element gcd(gf_element a, gf_element b);

gf_element exp(gf_element m, gf_element e, gf_element mod);

void quo_rem(polynomial a, polynomial b, polynomial& quo, polynomial& rem);

int degree(gf_element a);