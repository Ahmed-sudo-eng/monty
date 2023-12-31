#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
} instuction_t;

void push(stack_t **head, int element);
void pint(stack_t *head, int lineNumber);
void pop(stack_t **head, int lineNumber);
void swap(stack_t *head, int lineNumber);
void add(stack_t *head, int lineNumber);
void sub(stack_t *head, int lineNumber);
void mul(stack_t *head, int lineNumber);
void mod(stack_t *head, int lineNumber);
void divi(stack_t *head, int lineNumber);
void pchar(stack_t *head, int lineNumber);
void pstr(stack_t *head);
void pall(stack_t *head);
void rotl(stack_t **head);
void rotr(stack_t *head);
void free_stack(stack_t *head);
#endif
