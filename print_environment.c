#include "main.h"

/**
 * print_environment - a function that prints environment variables
 */
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
