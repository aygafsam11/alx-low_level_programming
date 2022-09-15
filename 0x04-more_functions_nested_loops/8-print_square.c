#include "main.h"

/**
 * print_square - prints hashes squares.
 * @size: size of the square.
 * Return: no return.
 */
void print_square(int size)
{
	int n, j;

	for (n = 0; n < size; n++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar(35);
		}
		if (n != size - 1)
			_putchar('\n');
	}
	_putchar('\n');
}
