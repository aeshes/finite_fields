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

polynomial decode(polynomial message)
{
	polynomial quo, rem = 0;

	quo_rem(message, g, quo, rem);

	if (rem == 0)
	{
		return quo;
	}
	else
	{
		// TODO: Error correcting
		return 0;
	}
}