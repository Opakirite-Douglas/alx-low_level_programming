#include <stdio.h>
/**
 * main - a C program that prints that prints a file followed by a new line
 *
 * Return: 1
 */

int main(void)
{
	char err[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-199\n";
	write(2,  err, 59);
	return (1);
}
