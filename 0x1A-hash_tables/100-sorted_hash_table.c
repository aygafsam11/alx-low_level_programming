#include "hash_tables.h"

/**
 * shash_table_create - create and initialize a hash table
 * @size: size of the hash table array
 *
 * Return: pointer to new hash table or NULL if failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **ha;

	/** create a list of pointers of size and assign it to hash_table**/
	ha = calloc(size, sizeof(shash_node_t *));
	if (ha == NULL)
		return (NULL);

	/** create a hash_table and assign list of pointers to array **/
	ht = calloc(1, sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = ha;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * replace_node_value - set value of nodes with same key string
 * @target: pointer to node target to change value
 * @value: value to set in node
 *
 * Return: 1 if success, 0 if failure
 */
int replace_node_value(shash_node_t *target, const char *value)
{
	/* free the target node's current value */
	/* strdup() the new value and set it in node */
	free(target->value);
	target->value = strdup(value);
	if (target->value == NULL)
		return (0);
	return (1);
}

/**
 * set_sorted_node - adds node to sorted linked list
 * @node: pointer to node
 * @shead: pointer to first node in sorted linked list
 * @shead: pointer to last node in sortedl linked list
 *
 * Return: 1 on success, 0 on failure
 */
int set_sorted_node(
	shash_node_t *node, shash_node_t **shead, shash_node_t **stail)
{
	shash_node_t *seeker = NULL;
	/* if shead empty, insert at head */
	if (*shead == NULL)
	{
		*shead = node;
		*stail = node;
		node->sprev = NULL;
		node->snext = NULL;
		/* printf("shead->key is %s\n", (*shead)->key); */
		/* printf("shead->value is %s\n", (*shead)->value); */

		return (1);
	}
	printf("*shead address is %p\n", (void*)*shead);
	/* else traverse list to find where value of new node fits */
	seeker = *shead;
	printf("seeker address is %p\n", (void*)seeker);
	while (seeker)
	{
		printf("got here\n");
		/* printf("shead->key is %s\n", (*shead)->key); */
		/* printf("shead->value is %s\n", (*shead)->value); */

		/* value inserted at head or in middle of ll */
		if (strcmp(seeker->value, node->value) < 0)
		{
			if (seeker == *shead)
			{
				/* printf("shead->key is %s\n", (*shead)->key); */
				/* printf("shead->value is %s\n", (*shead)->value); */

				node->snext = seeker;
				seeker->sprev = node;
				*shead = node;
				return (1);
			}
			else
			{
				node->snext = seeker;
				node->sprev = seeker->sprev;
				seeker->sprev = node;
				return (1);
			}
		}
		seeker = seeker->snext;
	}
	/* seeker is now last item in list */
	if (strcmp(seeker->value, node->value) < 0)
	{
		/* node inserted before seeker */
		node->snext = seeker;
		node->sprev = seeker->sprev;
		seeker->sprev = node;
		return (1);
	}
	else
	{
		/* node inserted after seeker and becomes tail */
		seeker->snext = node;
		node->sprev = seeker;
		node->snext = NULL;
		*stail = node;
		return (1);
	}
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: pointer to hash table
 * @key: input key as string
 * @value: input value as string
 *
 * Return: 1 if success, 0 if failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int key_idx;
	shash_node_t **array = NULL;
	shash_node_t *seeker = NULL;
	shash_node_t *new_next = NULL;
	shash_node_t *new_node = NULL;

	/* check if caller passing admissable arguments */
	if (!ht || !key || !*key || !value)
		return (0);
	array = ht->array;
	key_idx = key_index((unsigned char *)key, ht->size);
	if (array[key_idx])
	{
		/* traverse linked list for key == array[key_idx]->key */
		seeker = array[key_idx];
		while (seeker)
		{
			if (strcmp(seeker->key, key) == 0)
			{
				replace_node_value(seeker, value);
				return (1);
			}
			seeker = seeker->next;
		}
		/* if list isn't empty and key string unique set new_next */
		new_next = array[key_idx];
	}
	else
		/* if list empty set new_next to NULL */
		new_next = NULL;
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	/* duplicate and set value and key */
	new_node->value = strdup(value);
	new_node->key = strdup(key);
	new_node->next = new_next;
	/* set linked list head to new_node */
	array[key_idx] = new_node;
	printf("Key: %s:\n", new_node->key);
	printf("Value: %s:\n", new_node->value);
	printf("new_node address is %p\n", (void*)new_node);
	/* set in sorted linked list */
	set_sorted_node(new_node, &(ht->shead), &(ht->stail));
	return (1);
}


/**
 * shash_table_get - retrieve a value based on a given key
 * @ht: pointer to hash table
 * @key: input key as string
 *
 * Return: value associated with the element or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *seeker = NULL;

	/* check if caller passing admissable arguments */
	if (!ht || !key || !*key)
		return (NULL);

	/* check if shead */
	if (!ht->shead)
		return (NULL);

	seeker = ht->shead;
	/* loop sorted llist for matching key */
	while (seeker)
	{
		if (strcmp(seeker->key, key) == 0)
			return (seeker->value);
		seeker = seeker->next;
	}

	/* key not found */
	return (NULL);

}

/**
 * shash_table_print - function that prints a hash table
 * @ht: pointer to hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *seeker = NULL;

	/* check if ht is NULL return */
	if (!ht)
		return;

	printf("{");
	/* loop through indices of array for non-NULL */
	seeker = ht->shead;
	while (seeker)
	{
		printf("'%s': ", seeker->key);
		printf("'%s'", seeker->value);
		if (seeker->snext)
		{
			printf(", ");
			seeker = seeker->snext;
		}
		else
			break;
	}
	printf("}\n");
}
