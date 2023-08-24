#include "monty.h"
#include <stdarg.h>

/**
 * err_exit - prints error message and exit progrm
 * @stack: stack to be freed.
 * @format: pointer to message string.
 */
void err_exit(stack_t *stack, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			if (*++format == 's')
				fprintf(stderr, "%s", va_arg(ap, char *));
			else
				fprintf(stderr, "%d", va_arg(ap, int));
		}
		else
			write(STDERR_FILENO, &(*format), 1);
	}

	if (stack != NULL)
		free_stack(stack);
	if (operation.tokens != NULL)
		free_tok();
	if (operation.line != NULL)
		free(operation.line);
	if (operation.fp != NULL)
		fclose(operation.fp);

	va_end(ap);
	exit(EXIT_FAILURE);
}
