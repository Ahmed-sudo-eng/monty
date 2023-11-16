#include "monty.h"

/**
 * pint - a function that prints the value at the top of the stack,
 * followed by a new line
 * @head: a pointer that points to the first value of the stack
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void pint(stack_t *head, int lineNumber)
{
	stack_t *current = head;

	/* If the stack is empty */
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}
