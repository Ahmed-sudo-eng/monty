#include "monty.h"

/**
 * rotl - a function that rotates the stack to the top
 * @head: points to first element
 *
 * Return: Nothing
 */
void rotl(stack_t **head)
{
	stack_t *current = *head;
	stack_t *temp = *head;
	stack_t *newTop = (stack_t *) malloc(sizeof(stack_t));
	int nt;

	if (*head == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	nt = current->n;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
	newTop->n = nt;
	current->next = newTop;
	newTop->prev = current;
	newTop->next = NULL;
}
