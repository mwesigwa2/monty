#include "monty.h"

/**
 * f_pop - removes the top element of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
