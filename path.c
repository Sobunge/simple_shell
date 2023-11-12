#include "main.h"

/**
 * path - a function that handles the path
 *
 * @token: token variable
 * @args: args variable
 */
void path(char *token, char *args[])
{
	char *path;

	/* Get the PATH environment variable */
	path = getenv("PATH");

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
			perror("./shell");
			exit(1);
		}

		token = strtok(NULL, ":");
	}
}
