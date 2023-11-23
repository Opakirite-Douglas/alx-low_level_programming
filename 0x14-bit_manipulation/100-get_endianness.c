#include "main.h"

/**
 * get_endianness - This func simply checks the endianness.
 *
 * Return: 0 if big endian else return 1 if little endian
 */

int get_endianness(void)
{
	int a3Big;
	char *b3Little;

	a3Big = 1;
	b3Little = (char *)&a3Big;
	return (*b3Little);
}
