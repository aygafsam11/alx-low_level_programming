#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - sum of  the args
 * @argc: Argument count
 * @argv: Array of argument strings
 *
 * Return: 0 for successful exit
 */
int main(int argc, char *argv[])
{

	int i = 0;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (!isdigit(*argv[i]))
			{
				printf("Error\n");
			}
			else
			{
				sum += atoi(argv[i]);
			}
		}
		printf("%d\n", sum);
	}

	return (0);
}
