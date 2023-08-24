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

/**
 * mul - performs multiplication operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void mul(stack_t **stack, unsigned int number)
{
	int prod;

	if (stack_len(*stack) < 2)
		err_exit(*stack, "L%d: can't mul, stack too short\n", number);

	prod = fpop(stack) * fpop(stack);
	fpush(stack, prod);
}

/**
 * fdiv - performs division operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void fdiv(stack_t **stack, unsigned int number)
{
	int top;
	int quotient;

	if (stack_len(*stack) < 2)
		err_exit(*stack, "L%d: can't div, stack too short\n", number);
	if (get_top(*stack) == 0)
		err_exit(*stack, "L%d: division by zero\n", number);

	top = fpop(stack);
	quotient = fpop(stack) / top;
	fpush(stack, quotient);
}

/**
 * mod - performs modulus operations
 *
 * @stack: a stack.
 * @number: line number.
 */
void mod(stack_t **stack, unsigned int number)
{
	int top;
	int rem;

	if (stack_len(*stack) < 2)
		err_exit(*stack, "L%d: can't mod, stack too short\n", number);
	if (get_top(*stack) == 0)
		err_exit(*stack, "L%d: division by zero\n", number);

	top = fpop(stack);
	rem = fpop(stack) % top;
	fpush(stack, rem);
}
