#include "monty.h"

/**
 * pchar - a function that prints the char at the top of the stack, followed
 * by a new line
 * @head: points to the first element
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void pchar(stack_t *head, int lineNumber)
{
	stack_t *top = head;

	/* If the stack is empty */
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (top->next != NULL)
		top = top->next;
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", top->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		exit(EXIT_FAILURE);
	}

}
