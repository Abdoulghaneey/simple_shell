#include "main.h"
/*
 * shell_execute - shell execution and proccessing
 * @tokens: a pointer to char pointer
 * @envp: environment variable
 * Return: status 1
 */
int shell_execute(char **tokens, char **envp)
{
	struct stat st;
	int p;
	bool isWildca, isPiped;
	char *command;
	int (*func)(char **);

	isWildca = isWildcard(tokens);	/* check for wildcard char */
	if (isWildca)
	{
		/* pass in the wildcard globbing*/
	}
	command = tokens[0];
	for (p = 0; tokens[p] != NULL; p++)	/* get length of tokens */
		;
	--p;
	func = get_op_func(command); /* builtins functions returned */
	if (func)
	{
		isPiped = isPipe_redir(tokens); /* please handle if piped */
		if (isPiped)
		{
			/* pass in the piped function */
		}
		func(tokens);
	}
	else if (stat(command, &st) == 0 && st.st_mode & S_IXUSR)
	{
		isPiped = isPipe_redir(tokens); /* please handle if piped */
		execute(p, tokens, envp); /*condition above check exec file*/
	}
	else
		printf("command %s doen't exist \n", command);
	return (1);
}
