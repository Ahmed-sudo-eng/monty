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
	char *opcode = NULL;
	char *arg = NULL;
	stack_t *head = NULL;
	int lineNumber = 1;

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
		opcode = strtok(line, " \n");
		if (opcode == NULL)
		{
			lineNumber++;
			continue;
		}
		arg = strtok(NULL, " \n");

		if (opcode[0] == 'p' && opcode[1] == 'u' && opcode[2] == 's' && opcode[3] == 'h')
			push(&head, atoi(arg));
		else if (opcode[0] == 'p' && opcode[1] == 'a' && opcode[2] == 'l' && opcode[3] == 'l')
			pall(head);
		else if (opcode[0] == 'p' && opcode[1] == 'i' && opcode[2] == 'n' && opcode[3] == 't')
			pint(head, lineNumber);
		else if (opcode[0] == 'p' && opcode[1] == 'o' && opcode[2] == 'p')
			pop(&head, lineNumber);
		else if (opcode[0] == 's' && opcode[1] == 'w' && opcode[2] == 'a' && opcode[3] == 'p')
			swap(head, lineNumber);
		else if (opcode[0] == 'a' && opcode[1] == 'd' && opcode[2] == 'd')
			add(head, lineNumber);
		else if (opcode[0] == 's' && opcode[1] == 'u' && opcode[2] == 'b')
			sub(head, lineNumber);
		else if (opcode[0] == 'n' && opcode[1] == 'o' && opcode[2] == 'p')
		{
			lineNumber++;
			continue;
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
			exit(EXIT_FAILURE);
		}

		lineNumber++;

	}

	free(line);
	free_stack(head);
	fclose(stream);
	return (0);
}
