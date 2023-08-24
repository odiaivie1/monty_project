#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#ifdef MONTY_H
#define UNUSED(x) ((void) (x))
#endif

/**
 * struct op_s - ADT for monty operations.
 * @fp: a pointer to a file argument.
 * @tokens: a pointer to tokenized line.
 * @line: a pointer to lines read from file.
 * @size: the size of memory allocated to line.
 * @mode: mode of operation; queue or stack.
 * @line_number: current line number.
 */
tydef struct op_s
{
	FILE *fp;
	char **tokens;
	char *line;
	size_t size;
	int mode;
	size_t line_number;
} op_t;
extern op_t operation;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
