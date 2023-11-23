#include "main.h"

/**
 * clear_bit - This func simply sets the value of a bit to 0 at a given index.
 *
 * @index: My ind
 *
 * @n: The Num
 *
 * Return: 1(SUCCESS) else -1(ERROR)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if  (index > sizeof(n) * 8)
	{
		return (-1);
	}
	*n &= ~(1 << index);
	return (1);
}
