#include "monty.h"

/**
 * pstr - a function that prints the string starting at the top of the stack,
 * followed by a new line
 * @head: points to the first element
 *
 * Return: Nothing
 */
void pstr(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
	{
		printf("\n");
		return;
	}
	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		if (current->n > 0 && current->n <= 127)
			printf("%c", current->n);
		else
			break;
		current = current->prev;
	}
	printf("\n");
}
