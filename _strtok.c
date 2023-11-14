#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 *_strtok - Custom implementation of strtok.
 *
 *@str - The string to be tokenized.
 *@delim - The delimiter characters.
 *Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken = NULL;  /* Static variable to maintain state between calls */
	char *tokenStart;

	if (str != NULL)
	{
		lastToken = str;
	} else
	{
		/* If str is NULL, continue tokenizing from the last saved position */
		if (lastToken == NULL || *lastToken == '\0')
		{
			return (NULL);  /* No more tokens */
		}
	}
	
	/* Skip leading delimiters */
	while (*lastToken && strchr(delim, *lastToken))
	{
		lastToken++;
	}
	
	/* If at the end of the string, return NULL */
	if (*lastToken == '\0')
	{
		return (NULL);
	}
	/* Find the end of the token */
	tokenStart = lastToken;
	while (*lastToken && !strchr(delim, *lastToken))
	{
		lastToken++;
	}
	
	/* Null-terminate the token */
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}
	
	return (tokenStart);
}
