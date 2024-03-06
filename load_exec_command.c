#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * execute - load the command to execute
 * @argv: arguments
 * @envp: environment variables
 * @argc: integer
 * Return: integer value 0 success
 */
int execute(int argc, char **argv, char **envp)
{
	pid_t child_pid;
	int status;

	if (argc < 1)
	{
		printf("add more than one argument\n");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(argv[1], argv, envp) == -1)
		{
			printf("execve error\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
