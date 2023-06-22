#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;

	(*head) = temp;
}
