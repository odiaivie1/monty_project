#include "monty.h"

/**
 * free_tok - Frees an array of pointers.
 */
void free_tok(void)
{
	int i;

	for (i = 0; operation.tokens[i] != NULL; i++)
		free(operation.tokens[i]);
	free(operation.tokens);
}

/**
 * isnum - checks if string argument represents a number.
 *
 * @s: points to string argument.
 * Return: 1 if s is a number, otherwise 0.
 */
int isnum(char *s)
{
	int i = 0;

	i += strspn(s, "+-");
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
