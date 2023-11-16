#include "monty.h"

/**
 * pint - a function that prints the value at the top of the stack,
 * followed by a new line
 * @head: a pointer that points to the first value of the stack
 *
 * Return: Nothing
 */
void pint(stack_t *head)
{
	stack_t *current = head;

	while (current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}
