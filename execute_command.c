#include "main.h"

/**
 * execute_command - a function that executes commands
 *
 * @input: input variable
 * @argv: argv argument
 */
void execute_command(char input[], char argv[])
{
	char *token;
	char *delim = " \t\n";
	int status = 0;  /* Default status for logical AND */

	/* Tokenize the input */
	token = _strtok(input, delim);

	while (token != NULL)
	{
		tokenizer(argv, status, token, delim);

		token = _strtok(NULL, delim);
	}
}

