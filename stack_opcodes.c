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
