#include "monty.h"

/**
 * add - a function that adds the top two elements of the stack
 * @head: points to the first element
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void add(stack_t *head, int lineNumber)
{
	stack_t *current = head;
	stack_t *temp = NULL;

	/* If the stack contains less than two elements */
        if (head == NULL || head->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
                exit(EXIT_FAILURE);
        }
        /* ELSE */
	while (current->next->next != NULL)
		current = current->next;
	current->n = current->n + current->next->n;
	temp = current->next;
	current->next = NULL;
	free(temp);
}
