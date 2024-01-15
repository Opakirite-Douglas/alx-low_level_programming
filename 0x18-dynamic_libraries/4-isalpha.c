#include "main.h"

/**
 * _isalpha - To check alphabets
 * @c: Character to be checked
 * Return: 1 if c is an alphabet else return 0
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
