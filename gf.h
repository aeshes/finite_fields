#pragma once

using gf_element = unsigned int;
using polynomial = unsigned int;


gf_element add(gf_element a, gf_element b);

gf_element multiply(gf_element a, gf_element b, gf_element mod);

polynomial multiply(polynomial a, polynomial b);

polynomial rem(polynomial a, polynomial b);

polynomial gcd(polynomial a, polynomial b);

polynomial exp(polynomial m, int e, polynomial mod);

void quo_rem(polynomial a, polynomial b, polynomial& quo, polynomial& rem);

int degree(polynomial a);