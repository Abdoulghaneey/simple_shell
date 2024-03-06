#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "main.h"
/**
 *main - _strtok tokenizer
 *@line: string buffer
 *Return: char pointer
 */
char *_strtok(char *line)
{
	char *delim = " ";
	char *str;
	char *token;
	int i = 0;

	if (line == NULL)
	{
		printf("line is null");
		exit (EXIT_FAILURE);
	}
	for (str = line; ; str = NULL)
	{
		token = strtok(str, delim);
		if (token == NULL)
			break;
		if (++i == 1)
			break;
	}
	return (token);
}
