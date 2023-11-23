#include "main.h"

/**
 * binary_to_uint - This is a program that will simply
 * convert a binary number to a non negative integer
 *
 * @b: Is simply a pointer to the string
 *
 * Return: number converted else 0(ERROR)
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int theNumber;
	int osd = 0;

	theNumber = 0;
	if (!b)
	{
		return (0);
	}
	for (osd = 0; b[osd] != '\0'; osd++)
	{
		if (b[osd] != '0' && b[osd] != '1')
		{
			return (0);
		}
	}
	for (osd = 0; b[osd] != '\0'; osd++)
	{
		theNumber <<= 1;
		if (b[osd] == '1')
		{
			theNumber += 1;
		}
	}
	return (theNumber);
}
