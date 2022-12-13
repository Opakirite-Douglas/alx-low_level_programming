#include <stdio.h>

/**
 * main - To print the alphabets in lowercase, and then in uppercase.
 *
 * Return: 0 (success)
 */

int main(void)

{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)

	putchar(letter);

	for (letter = 'A'; letter <= 'Z'; letter++)

	putchar(letter);

	putchar('\n');

	return (0);

}
