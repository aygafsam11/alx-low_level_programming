#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the first 50 Fibonacci numbers
 *		starting with 1 and 2 folled by a new line
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int count;
	unsigned long fin1 = 0, fin2 = 1, sum;

	for (count = 0; count < 50; ++count)
	{
		sum = fin1 + fin2;
		printf("%lu", sum);

		fin1 = fin2;
		fin2 = sum;

		if (count == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
