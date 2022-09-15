#include "main.h"

/**
 * print_square - print a square using the character #
 *
 * @size: is the size of the square
 *
 * Return: Always 0 (Success)
*/

void print_square(int size)
{
	int row, col;

	for (row = 1; row <= size; ++row)
	{
		for (col = 1; col <= size; ++col)
			_putchar('#');
		_putchar('\n');
	}
}
