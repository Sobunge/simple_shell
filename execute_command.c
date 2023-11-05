#include "main.h"
/**
 * execute_command - a function that executes commands
 *
 * @input: input variable
 */
void execute_command(char input[])
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
		/* Execute the command using execve */
		/* Allocate memory for the args array */
		char *args[2];

		args[0] = input;
		args[1] = NULL;

		execve(input, args, NULL);
		/* If execve returns, it means the command was not found */
		perror("./shell");
		exit(1);
	} else
	{
		/* In the parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}
