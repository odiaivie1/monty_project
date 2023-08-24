#include "monty.h"

/**
 * add - performs addition operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void add(stack_t **stack, unsigned int number)
{
	int sum;

	if (stack_len(*stack) < 2)
		err_exit(*stack, "L%d: can't add, stack too short\n", number);

	sum = fpop(stack) + fpop(stack);
	fpush(stack, sum);
}

/**
 * sub - performs subtraction operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void sub(stack_t **stack, unsigned int number)
{
	int diff, tmp;

	if (stack_len(*stack) < 2)
		err_exit(*stack, "L%d: can't sub, stack too short\n", number);

	tmp = fpop(stack);
	diff = fpop(stack) - tmp;
	fpush(stack, diff);
}
