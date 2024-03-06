#include "shell.h"

/**
 * sep_cmds - sep cmds by semicolon
 * @us_input: group of strngs
 * Return: strng parsed neededfor use
 */

char **sep_cmds(char *us_input)
{
	char **cmds;
	char *cmd;
	int c;
	int bufer_size = BUFSIZE;

	if (us_input[0] == ' ' && us_input[_strlen(us_input)] == ' ')
		exit(0);
	if (us_input == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * bufer_size);
	if (!cmds)
	{
		free(cmds);
		perror("hsh");
		return (NULL);
	}
	cmd = _strtok(us_input, ";&");
	for (c = 0; cmd; c++)
	{
		cmds[c] = cmd;
		cmd = _strtok(NULL, ";&");
	}
	cmds[c] = NULL;

	return (cmds);
}
