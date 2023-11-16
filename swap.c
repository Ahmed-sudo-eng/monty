#include "monty.h"

/**
 * swap - a function that swaps the top two elements of the stack
 * @head: points to the first element
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void swap(stack_t *head, int lineNumber)
{
	stack_t *current = head;
	int s1, s2;

	/* If the stack contains less than two elements */
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (current->next->next != NULL)
		current = current->next;
	s1 = current->n;
	s2 = current->next->n;

	current->n = s2;
	current->next->n = s1;
}
