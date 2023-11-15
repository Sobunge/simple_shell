#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARG_LENGTH 20
#define MAX_ARGS 10

void execute_command(char *command)
{
	char *args[MAX_ARGS];
	int i = 0;

	/* Tokenize the command into arguments */
	char *token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL; /* Null-terminate the argument list */

	/* Fork a new process */
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		/* Execute the command in the child */
		execve(args[0], args, NULL);

		/* If execve fails */
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		/* Wait for the child to complete */
		waitpid(pid, NULL, 0);
	}
}

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		/* Print shell prompt */
		printf("$ ");

		/* Read user input */
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		/* Remove trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Exit the shell if the user enters 'exit' or 'quit' */
		if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0)
		{
			break;
		}

		/* Execute the command */
		execute_command(input);
	}

	printf("Exiting the shell.\n");

	return 0;
}

