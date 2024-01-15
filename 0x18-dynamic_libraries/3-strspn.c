#include "main.h"

/**
 * _strspn - The entry point for the program
 * @s: an input
 * @accept: an input
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int h;

	while (*s)
	{
		for (h = 0; accept[h]; h++)
		{
			if (*s == accept[h])
			{
				n++;
				break;
			}
			else if (accept[h + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
