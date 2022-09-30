#include <stdio.h>

/**
 * main - Print the of args
 * @argc: Argument count
 * @argv: Array of argument strings
 *
 * Return: 0 for succesful exit
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}


	return (0);
}
