#include "main.h"

/**
 * execute_input - a function that executes commands
 *
 * @argv: argv argument
 * @token: token variable
 */
void execute_input(char *token, char argv[])
{

	/* Fork a child process for each command */
	pid_t pid = fork();

	if (pid < 0)
	{
		perror(argv);
		exit(1);
	} else if (pid == 0)
	{
		/* In the child process */
		char *args[64];
		int i = 0;

		handle_path(token, args, i, argv);
		/*
		 * If the loop completes, the command
		 * was not found in any directory in PATH
		 */

		perror(argv);
		exit(1);
	} else
	{
		/* In the parent process */
		int child_status;

		waitpid(pid, &child_status, 0);

	}
}
