#include "main.h"

/**
 * set_environment_variable - a function that sets environment variable
 *
 * @variable: variable argument
 * @value: value argument
 * @argv: argv variable
 */
void set_environment_variable(const char *variable, const char *value,
		char argv[])
{
	if (setenv(variable, value, 1) != 0)
	{
		print_error("Failed to set environment variable");
	} else
	{
		perror(argv);
	}
}
