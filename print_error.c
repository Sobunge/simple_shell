#include "main.h"

/**
 * print_error - a function that prints standard errors
 *
 * @message: message variable
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}
