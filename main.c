#include "monty.h"

/**
 * main - interpreter for monty scripting language
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: On success (0) and (1) on failure
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	char *fileName;
	char *cmd = NULL;
	char *arg = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* File opening */
	fileName = argv[1];
	stream = fopen(fileName, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	/* Main Programme */
	while ((_getline(&line, &len, stream)) != -1)
	{
		cmd = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");

		if (cmd[0] == 'p' && cmd[1] == 'u' && cmd[2] == 's' && cmd[3] == 'h')
			push(&head, atoi(arg));
		if (cmd[0] == 'p' && cmd[1] == 'a' && cmd[2] == 'l'
				  && cmd[3] == 'l')
			pall(head);

	}

	free(line);
	free_stack(head);
	fclose(stream);
	return (0);
}
