#include "main.h"

/**
 * _isupper - function that checks for uppercase characters
 * @c: character to be checked
 *
 * Return: 1 if uppercase, otherwise return 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}
