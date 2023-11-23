#include "main.h"

/**
 * flip_bits - This func simply returns the number of bits
 * you would need to flip to get from one number to another.
 *
 * @m: num2
 *
 * @n: num1
 *
 * Return: bits changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int myBitCounter = 0;
	unsigned long int present;
	unsigned long int Xclusv = n ^ m;
	int osd = 63;

	while (osd >= 0)
	{
		osd--;
		present = Xclusv >> osd;
		if (present & 1)
			myBitCounter++;
	}
	return (myBitCounter);
}
