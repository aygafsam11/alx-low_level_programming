#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - printte numbers
 * @n: number of argument to sum
 * Ret all argument
 * @separator: item to use ot separaurn: sum of all argument
 */


void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	char *c;


	va_list ap;

	va_start(ap, n);

	if (!separator)
		return;

	for (i = 0; i < n; i++)
	{
		c =  va_arg(ap,  char*);
		printf("%s%s", c == NULL ? "(nil)" : c, i != (n - 1) ? separator : "");
	}



	va_end(ap);
	putchar('\n');


}
