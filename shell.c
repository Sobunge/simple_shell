#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

extern char **environ;

/**
 * handle_input - hadle input function
 *
 * @command: command argument
 */
void handle_input(char *command)
{

	/* Fork a child process */
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		/*
		* In the child process
		* Execute the command using execve
		*/
		char *args[1];

		args[0] = command;
		args[1] = NULL;

		if (execve(args[0], args, environ) == -1)
		{
			/* If execve fails, print an error message */
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	} else
	{
		/* In the parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * main - main function
 * Return:
 * - Returns 0 upon successful execution.
 */
int main(void)
{
	char command[100];

	while (1)
	{
		/* Display the prompt */
		printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			/* Handle end of file (Ctrl+D) */
			break;
		}

		/* Remove the newline character from the command */
		command[strcspn(command, "\n")] = '\0';

		handle_input(command);
	}

	return (0);
}

