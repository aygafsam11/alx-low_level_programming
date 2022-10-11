#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - initialize a variable of type struct dog
 * @d: pointer to struct dog
 */

void print_dog(struct dog *d)
{

	if (d)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}

}
