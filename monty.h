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

/* Instruction functions */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void fdiv(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void fstack(stack_t **stack, unsigned int line_number);
void fqueue(stack_t **stack, unsigned int line_number);

/* Stacks and Queues Operations*/
stack_t *fpush(stack_t **stack, int num);
void print_stack(const stack_t *stack);
void free_stack(stack_t *stack);
int is_empty(stack_t *stack);
int fpop(stack_t **stack);
size_t stack_len(const stack_t *stack);
stack_t *enqueue(stack_t **stack, int num);
void fswap(stack_t **stack);
int get_top(stack_t *stack);
void print_stack_str(const stack_t *stack);
int lpop(stack_t **stack);

/* Helper functions */
char **strtow(char *str);
size_t strchr_no(const char *s, int c);
void free_tok(void);
int isnum(char *s);
void err_exit(stack_t *stack, const char *msg, ...);
void execute_opcode(stack_t **stack, unsigned int line_number);

#endif /* monty.h */
