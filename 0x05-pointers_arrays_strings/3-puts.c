#include "main.h"

/**
 *_puts - function that prints a string
 *@str: the string
 *
 *Return: the length of the string
*/

void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str++);
}
_putchar('\n');
}
