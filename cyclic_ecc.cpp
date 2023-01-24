#include "cyclic_ecc.h"

/*
* Generating polynomials:
* 0x0D x^3 + x^2 + 1
* 0x0B x^3 + x + 1
* 0x1D x^4 + x^3 + x^2 + 1
*/

const polynomial g = 0x0B;

polynomial encode(polynomial message)
{
	return multiply(message, g);
}