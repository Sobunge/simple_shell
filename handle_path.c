#include "main.h"

/**
 * handle_path - a function that handles paths
 *
 * @input: input variable
 * @args: string entered
 * @argv: argv argument
 * @i: integer i
 */
void handle_path(char input[], char *args[], int i, char argv[])
{
	/* Tokenize the input */
	char *token;

	token = _strtok(input, " \t\n");
	while (token != NULL)
	{
		args[i++] = token;
		token = _strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	if (strchr(args[0], '/') == NULL)
	{
		path(token, args, argv);
	} else
	{
		/* The command contains a / character, so it's already a full path */
		execve(input, args, environ);
		printf("%s: 1 %s: Permission denied", argv, args[0]);
		perror(argv);
		exit(1);
	}
}
