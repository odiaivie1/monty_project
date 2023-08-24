#include "monty.h"

/**
 * push - pushes to stack operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void push(stack_t **stack, unsigned int number)
{
	int element;

	if (operation.tokens[1] == NULL || isnum(operation.tokens[1]) == 0)
		err_exit(*stack, "L%d: usage: push integer\n", number);

	/* Add element to stack */
	element = atoi(operation.tokens[1]);
	if (operation.mode == 0) /* Add on top of stack */
	{
		if (fpush(stack, element) == NULL)
			err_exit(*stack, "Error: malloc failed\n");
	}
	else /* Add at the end of queue */
	{
		if (enqueue(stack, element) == NULL)
			err_exit(*stack, "Error: malloc failed\n");
	}
}

/**
 * pop - pops from stack.
 *
 * @stack: a stack.
 * @number: line number.
 */
void pop(stack_t **stack, unsigned int number)
{
	if (is_empty(*stack))
		err_exit(*stack, "L%d: can't pop an empty stack\n", number);
	fpop(stack);
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: a stack.
 * @number: line number.
 */
void rotr(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	if (stack_len(*stack) > 1)
		fpush(stack, lpop(stack));
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: a stack.
 * @number: line number.
 */
void rotl(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	if (!is_empty(*stack))
		enqueue(stack, fpop(stack));
}
