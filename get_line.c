#include "main.h"

#define BUFFER_SIZE 512

/**
 * custom_getline - Custom implementation of a line-reading function.
 *
 * Return: A dynamically allocated string representing a line of input or
 *         NULL if the end of file is reached without any input.
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static ssize_t bytes_read;

	char *line = NULL;
	size_t line_size = 0;
	int c;

	while (1)
	{

		if ((size_t)buffer_index >= (size_t)bytes_read)
		{
			bytes_read = read(0, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (line_size == 0)
					return (NULL);
				break;
			}
			buffer_index = 0;
		}

		c = buffer[buffer_index++];
		if (c == '\n' || c == EOF)
			break;

		line = realloc(line, ++line_size);
		line[line_size - 1] = (char)c;
	}

	return (line ? realloc(line, line_size + 1) : NULL);
}
