#include "monty.h"

/**
 * fstack - change mode to stack mode.
 *
 * @stack: a stack.
 * @number: line number.
 */
void fstack(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
	operation.mode = 0;
}

/**
 * fqueue - change mode to queue mode
 *
 * @stack: a stack.
 * @number: line number.
 */
void fqueue(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
	operation.mode = 1;
}

/**
 * nop - does nothing
 *
 * @stack: a stack.
 * @number: line number.
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
}

/**
 * get_top - get the element at the top of stack.
 *
 * @stack: stack.
 * Return: the top element.
 */
int get_top(stack_t *stack)
{
	return (stack->n);
}
