#include "main.h"

/**
 * execute_command - a function that executes commands
 *
 * @argv: argv argument
 * @input: input variable
 */
void execute_command(char input[], char argv[])
{
	pid_t pid;

	/* Fork a child process */
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	} else if (pid == 0)
	{
		/* In the child process */
		char *args[64];
		int i = 0;

		handle_path(input, args, i);
		/*
		* If the loop completes,
		* the command was not found in any directory in PATH
		*/
		perror(argv);
		exit(1);
	} else
	{
		/* In the parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}
