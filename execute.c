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
		/* Tokenize the input */
		char *token;
		char *args[64];
		int i = 0;

		token = strtok(input, " \t\n");
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}
		args[i] = NULL;

		/* Get the PATH environment variable */
		char *path = getenv("PATH");

		if (path == NULL)
		{
			perror("PATH environment variable not set");
			exit(1);
		}

		/* Try to execute the command in directories listed in PATH */
		token = strtok(path, ":");
		while (token != NULL)
		{
			char commandPath[256];

			snprintf(commandPath, sizeof(commandPath), "%s/%s", token, args[0]);

			/* Check if the command exists in the current directory */
			if (access(commandPath, X_OK) == 0)
			{
				execve(commandPath, args, NULL);
				perror("execve failed");
				exit(1);
			}

			token = strtok(NULL, ":");
		}

		/*
		* If the loop completes,
		* the command was not found in any directory in PATH
		*/
		printf("Command not found: %s\n", args[0]);
		exit(1);
	} else
	{
		/* In the parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}
