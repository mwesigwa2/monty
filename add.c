#include "monty.h"

/**
 * f_add - adds the top two elements of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	*head = temp->next;
	free(temp);
}

