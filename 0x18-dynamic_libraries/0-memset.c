#include "main.h"

/**
 * _memset - Fill a block of memory as specified
 * @s: initial address of memory to be filled
 * @b: value
 * @n: number of bytes
 *
 * Return: changes with new value for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
