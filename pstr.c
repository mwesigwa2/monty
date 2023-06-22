#include "monty.h"

/**
 * f_pstr - prints the string at the top of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
