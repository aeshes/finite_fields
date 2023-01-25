#include "cyclic_ecc.h"
#include "numutils.h"

/*
* Generating polynomials:
* 0x0D x^3 + x^2 + 1
* 0x0B x^3 + x + 1
* 0x1D x^4 + x^3 + x^2 + 1
*/

const gf32 g = 0x0B;
const int ERROR_CORRECTING_COUNT = 1;
const int CODE_LENGTH = 7;

gf32 encode(gf32 message)
{
	return multiply(message, g);
}

static inline gf32 ror(gf32 syndrome)
{
	return (syndrome >> 1) | (syndrome << (CODE_LENGTH - 1)) & 0x7F;
}

static inline gf32 rol(gf32 syndrome)
{
	return (syndrome << 1) | (syndrome >> (CODE_LENGTH - 1)) & 0x7F;
}

gf32 correct_errors(gf32 message, gf32 syndrome)
{
	if (hamming_norm(syndrome) <= ERROR_CORRECTING_COUNT)
	{
		return message ^ syndrome;
	}
	else
	{
		for (int i = 0; i < CODE_LENGTH; i++)
		{
			println(syndrome, 7);
			syndrome = rol(syndrome);
			gf32 r = rem(syndrome, g);
			int wt = hamming_norm(r);

			if (hamming_norm(rem(syndrome, g)) <= ERROR_CORRECTING_COUNT)
			{
				return message ^ syndrome;
			}
		}
	}

	return 0;
}

gf32 decode(gf32 message)
{
	gf32 decoded, syndrome = 0;

	div(message, g, decoded, syndrome);

	if (syndrome == 0)
	{
		return decoded;
	}
	else
	{
		message = correct_errors(message, syndrome);
		
		div(message, g, decoded, syndrome);

		return decoded;
	}
}