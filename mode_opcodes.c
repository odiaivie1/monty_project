#include "monty.h"

/**
 * fstack - change mode to stack mode.
 *
 * @stack: a stack.
 * @number: line number.
 */
void fstack(stack_t **stack, unsigned int number)
{
	UNUSED(stack);
	UNUSED(number);

	operation.mode = 0;
}

/**
 * fqueue - change mode to queue mode
 *
 * @stack: a stack.
 * @number: line number.
 */
void fqueue(stack_t **stack, unsigned int number)
{
	UNUSED(stack);
	UNUSED(number);

	operation.mode = 1;
}
