#include "monty.h"

op_t operation = {NULL, NULL, NULL, 0, 0, 0};

/**
 * main - program control.
 *
 * @ac: number of arguments passed to program.
 * @av: an array of pointers to arguments.
 * Return: always EXIT_SUCCESS.
 */
int main(int ac, char **av)
{
	size_t comment_pos, len;
	stack_t *head;

	if (ac != 2)
		err_exit(NULL, "USAGE: monty file\n");
	operation.fp = fopen(av[1], "r");
	if (operation.fp == NULL)
		err_exit(NULL, "Error: Can't open file %s\n", av[1]);

	head = NULL;

	/* Read lines from file */
	while (getline(&(operation.line), &(operation.size), operation.fp) != -1)
	{
		operation.line_number++;

		len = strlen(operation.line);
		operation.line[len - 1] = '\0';

		comment_pos = strchr_no(operation.line, '#');
		if (comment_pos < len) /* Handle comments */
			operation.line[comment_pos] = '\0';

		operation.tokens = strtow(operation.line);
		if (operation.tokens == NULL)
			continue;

		execute_opcode(&head, operation.line_number);
		free_tok();
	}
	fclose(operation.fp);
	free(operation.line);
	free_stack(head);
	return (EXIT_SUCCESS);
}
