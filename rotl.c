#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *current;
	(void)line_number;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	current = (*head)->next;
	current->prev = NULL;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;

	(*head) = current;
}
