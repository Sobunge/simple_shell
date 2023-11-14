#include "main.h"

/**
 * set_environment_variable - a function that sets environment variable
 *
 * @variable: variable argument
 * @value: value argument
 */
void set_environment_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		print_error("Failed to set environment variable");
	} else
	{
		printf("Environment variable %s set to %s\n", variable, value);
	}
}
