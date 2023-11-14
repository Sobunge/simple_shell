#include "main.h"

/**
 * unset_environment_variable - a function that unsets environment variable
 *
 * @variable: variable argument
 */
void unset_environment_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		print_error("Failed to unset environment variable");
	} else
	{
		perror("./shell");
	}
}
