#include "monty.h"

/**
 * print_stack_str - prints a stack in string form
 *
 * @stack: stack.
 */
void print_stack_str(const stack_t *stack)
{
	while (stack != NULL)
	{
		if (stack->n == 0 || stack->n > 127)
			break;
		putchar(stack->n);
		stack = stack->next;
	}
	putchar('\n');
}
