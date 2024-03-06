#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "main.h"
#define BUFSIZE 64
/**
 *_strtok - _strtok tokenizer
 *@line: string buffer
 *Return: char pointer to pointer
 */
char **_strtok(char *line)
{
	char *delim = " \t\r\n\a";
	char *str;
	char *token;
	int bufsize = BUFSIZE;
	char **tokens = malloc(bufsize * sizeof(char *));
	int i = 0;

	if (line == NULL)
	{
		printf("line is null");
		exit(EXIT_FAILURE);
	}
	for (str = line; ; str = NULL)
	{
		token = strtok(str, delim);
		if (token == NULL)
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "error memory re-allocation");
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
