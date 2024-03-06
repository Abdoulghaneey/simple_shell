#include "main.h"
/**
 * lsh_cd - change directory
 * @args: the argument to cd
 * Return: integer
*/
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * lsh_help - help function
 * @args: the argument to cd
 * Return: integer
*/
int lsh_help(char __attribute__ ((unused)) **args)
{
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	printf("Use the man command for information on other programs.\n");
	return (0);
}
/**
 * lsh_exit - exit function
 * @args: the argument to exit
 * Return: integer
*/
int lsh_exit(char __attribute__ ((unused)) **args)
{
	return (0);
}
