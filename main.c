#include "monty.h"
#define MAX_LEN 1024

bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty
 * @argc: number of arguments
 * @argv: string with monty file
 *
 * Return: 0 (sucess)
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t *top = NULL;
	unsigned int line_number = 0;
	char data[MAX_LEN];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bus.file = fd;

	while (fgets(data, MAX_LEN, fd) != NULL)
	{
		line_number++;
		bus.data = data;
		exec(bus.data, &top, line_number, fd);
	}
	free_stack(top);
	fclose(fd);

	return (0);
}
