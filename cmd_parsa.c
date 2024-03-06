#include "shell.h"

/**
 * parse_cmd - The func resolves stdin command
 * @std_input: std input
 * Return: resolved strng needed for args
 */

char **parse_cmd(char *std_input)
{
	char **argms;
	char *argm;
	int c;
	int bufer_size = BUFSIZE;

	if (std_input[0] == ' ' && std_input[_strlen(std_input)] == ' ')
		exit(0);
	if (std_input == NULL)
		return (NULL);
	argms = malloc(sizeof(char *) * bufer_size);
	if (!argms)
	{
		free(argms);
		perror("hsh");
		return (NULL);
	}
	argm = _strtok(std_input, "\n\t\r\a ");
	for (c = 0; argm; c++)
	{
		argms[c] = argm;
		argm = _strtok(NULL, "\n\t\r\a ");
	}
	argms[c] = NULL;

	return (argms);
}
