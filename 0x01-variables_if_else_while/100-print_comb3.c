#include <stdio.h>

/**
 * main - A program that prints all possible different
 * combinations of two digits.
 *
 * Return: 0 (success)
 */


int main(void)
	{
		int num1, num2;

		num1 = 01;

		while (num1 < 89)
	{
		num2 = 01;
		while (num2 < 89)
		putchar(num1);
		putchar(num2);
		num2++;
		putchar(',');
		putchar(' ');
		num1++;
	}

	putchar('\n');

	return (0);



}
