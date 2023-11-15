#include "monty.h"

void push(stack_t **head, int element)
{
	stack_t *newNode = (stack_t *) malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (*head == NULL)
	{
		newNode->n = element;
		newNode->prev = NULL;
		newNode->next = NULL;
		*head = newNode;

		return;
	}
	while (current->next != NULL)
		current = current->next;
	newNode->n = element;
	newNode->prev = current;
	newNode->next = NULL;
	current->next = newNode;
}
