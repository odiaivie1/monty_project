#include "monty.h"

/**
 * pchar - prints the character equivalent of the top element of stack
 *
 * @stack: a stack.
 * @number: line number.
 */
void pchar(stack_t **stack, unsigned int number)
{
	int top;

	if (is_empty(*stack))
		err_exit(*stack, "L%d: can't pchar, stack empty\n", number);

	top = get_top(*stack);
	if (top > 127)
		err_exit(*stack, "L%d: can't pchar, value out of range\n", number);
	printf("%c\n", top);
}

/**
 * pstr - prints stack as a string
 *
 * @stack: a stack.
 * @number: line number.
 */
void pstr(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	print_stack_str(*stack);
}

/**
 * pall - prints stack
 *
 * @stack: a stack.
 * @number: line number.
 */
void pall(stack_t **stack, unsigned int number)
{
	UNUSED(number);

	print_stack(*stack);
}

/**
 * pint - prints top element.
 *
 * @stack: a stack.
 * @number: line number.
 */
void pint(stack_t **stack, unsigned int number)
{
	if (is_empty(*stack))
		err_exit(*stack, "L%d: can't pint, stack empty\n", number);
	printf("%d\n", get_top(*stack));
}
