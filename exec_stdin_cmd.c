#include "shell.h"

/**
 * check_cmd - checkinthe cmd
 * @cmd: cmd in quest
 * @us_input: user input
 * @t: exec time
 * @argv: Args prior to the init of prog(argv[0] == prog namefor shell)
 * Return: 0 when executed successfully
 */

int check_cmd(char **cmd, char *us_input, int t, char **argv)
{
	int cond;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], t, argv);
			(all_free(cmd, us_input));
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&cond);
	if (WIFEXITED(cond))
	{
		if (WEXITSTATUS(cond) == 0)
			return (0);
		else if (WEXITSTATUS(cond) == 2)
			return (2);
		else if (WEXITSTATUS(cond) == 127)
			return (127);
	}
	return (127);
}

/**
 * treat_signal - set ctrl + C not to kill shell
 * @s: sig in quest
 */

void treat_signal(int s)
{
	if (s == SIGINT)
	{
		PRINT("\n$ ");
	}
}
