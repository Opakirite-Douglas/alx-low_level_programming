#include "main.h"

/**
 * set_bit - This func simply sets the value of a bit to 1 at a given index.
 *
 * @index: My Ind
 *
 * @n: The Num
 *
 * Return: 1(SUCCESS) else -1(ERROR)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit2Set;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	{
		return (-1);
	}
	bit2Set = 1 << index;
	*n = *n | bit2Set;

	return (1);
}
