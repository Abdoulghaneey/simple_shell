#include "main.h"
/*
 * loop - processing
 * @envp: environment variable
 * Return: void
 */
void shell_loop(char **envp)
{
	char *line;
	char **tokens;
	int status;

	do {
		printf("$ ");
		line = _getline();	/* returns the read lines */
		if (line == NULL)
			errormessage("getline returned Null");
		tokens = _strtok(line);	/* tokenize lines and save in memory*/
		if (tokens == NULL)
			errormessage("tokenize returned Null");
		status = shell_execute(tokens, envp);
		free(line);
		free(tokens);
	} while (status);
}
/*
 * errormessage - prints the error
 * @s: the string message
 * Return: void
 */
void errormessage(char *s)
{
	printf("! %s \n", s);
	exit(EXIT_FAILURE);
}
