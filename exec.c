#include "monty.h"

/**
 * exec - executes opcode
 * @data: content from file
 * @top: pointer to top of stack
 * @line_number: line number
 * @fd: file descriptor to file
 * Return: 0 (success)
 */
int exec(char *data, stack_t **top, unsigned int line_number, FILE *fd)
{
	unsigned int x = 0;
	char *op;
	instruction_t operations[] = {{"push", f_push},
		{"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap},
		{"add", f_add}, {"nop", f_nop},
		{"sub", f_sub}, {"div", f_div},
		{NULL, NULL}};

	op = strtok(data, " \n\t");
	bus.arg = strtok(NULL, " \n\t");

	if (op == NULL || op[0] == '#')
		return (0);

	while (operations[x].opcode != NULL)
	{
		if (strcmp(op, operations[x].opcode) == 0)
		{
			operations[x].f(top, line_number);
			return (0);
		}
		x++;
	}

	if (op || operations[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(fd);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	return (1);
}
