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

/**
 * print_stack - print stack
 *
 * @stack: stack
 */
void print_stack(const stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * free_stack - frees stack.
 *
 * @stack: stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * stack_len - length of stack.
 *
 * @stack: stack.
 * Return: length of stack.
 */
size_t stack_len(const stack_t *stack)
{
	size_t len;

	for (len = 0; stack != NULL; stack = stack->next)
		++len;
	return (len);
}
