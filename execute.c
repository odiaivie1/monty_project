#include "monty.h"

/**
 * execute_opcode - handles opcode execution.
 *
 * @stack: stack.
 * @line_number: line number.
 */
void execute_opcode(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"add", add},
		{"pop", pop},
		{"pint", pint},
		{"nop", nop},
		{"swap", swap},
		{"sub", sub},
		{"div", fdiv},
		{"mul", mul},
		{"mod", mod},
		{"stack", fstack},
		{"queue", fqueue},
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"pchar", pchar},
		{NULL, NULL}};
	int i;

	i = 0;
	while (cmd[i].opcode != NULL)
	{
		if (strcmp(cmd[i].opcode, operation.tokens[0]) == 0)
		{
			cmd[i].f(stack, line_number);
			return;
		}
		i++;
	}
	err_exit(*stack, "L%d: unknown instruction %s\n",
			line_number, operation.tokens[0]);
}
