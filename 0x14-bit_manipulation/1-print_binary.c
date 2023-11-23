#include "main.h"

/**
 * MyPower - this is a custom func
 * @power: index of exponential
 * @base: number or base of exponential
 * Return: Value
 */

unsigned long int MyPower(unsigned int base, unsigned int power)
{
	unsigned int a4Apple;
	unsigned long int num4Number = 1;

	for (a4Apple = 1; a4Apple <= power; a4Apple++)
	{
		num4Number *= base;
	}
	return (num4Number);
}

/**
 * print_binary - This prog will write a function that prints
 * the binary representation of a number.
 * @n: The number
 * Return: Nothing
 */

void print_binary(unsigned long int n)
{
	char osdflagMe;
	unsigned long int checkMe, MydivMe;

	osdflagMe = 0;
	MydivMe = MyPower(2, sizeof(unsigned long int) * 8 - 1);
	while (MydivMe != 0)
	{
		checkMe = n & MydivMe;
		if (checkMe == MydivMe)
		{
			osdflagMe = 1;
			_putchar('1');
		}
		else if (osdflagMe == 1 || MydivMe == 1)
		{
			_putchar('0');
		}
		MydivMe >>= 1;
	}
}
