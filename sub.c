#include "monty.h"

/**
 * sub - a function that subtracts the top element of the stack from the second
 * top element of the stack
 * @head: points to the first element
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void sub(stack_t *head, int lineNumber)
{
	stack_t *current = head;
	stack_t *temp;

	/* If stack has less than two elements */
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (current->next->next != NULL)
		current = current->next;
	current->n = current->next->n - current->n;
	temp = current->next;
	current->next = NULL;
	free(temp);
}
