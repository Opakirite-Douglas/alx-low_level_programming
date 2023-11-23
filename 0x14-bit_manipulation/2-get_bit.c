#include "main.h"

/**
 * get_bit - This function should return value of a bit at a given index
 *
 * @index: My index
 *
 * @n: The num
 *
 * Return: bit value else -1(ERROR)
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int osdCheckMe, osdDivMe;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	{
		return (-1);
	}
	osdDivMe = 1 << index;
	osdCheckMe = n & osdDivMe;

	if (osdCheckMe == osdDivMe)
	{
		return (1);
	}
	return (0);
}
