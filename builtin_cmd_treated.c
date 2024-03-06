#include "shell.h"

/**
 * builtin_chk - search whether the cmd is built in or not
 * @cmd: cmd in question
 * Return: 0 whensuccessful otherwise return -1
 */

int builtin_chk(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int c = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + c)->command)
	{
		if (_strngcmp(cmd[0], (fun + c)->command) == 0)
			return (0);
		c++;
	}
	return (-1);
}

/**
 * builtin_handle - resolve built in that are custom
 * @cmd: parsed_cmd_str arr
 * @cond: cond of previous exec
 * Return: 0  when Successful
 */

int builtin_handle(char **cmd, int cond)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", show_env},
		{"help", show_help},
		{"echo", builtin_echo},
		{"history", sh_history},
		{NULL, NULL}
	};
	int c = 0;

	while ((built_in + c)->command)
	{
		if (_strngcmp(cmd[0], (built_in + c)->command) == 0)
		{
			return ((built_in + c)->function(cmd, cond));
		}
		c++;
	}
	return (-1);
}

/**
 * builtin_exit - exit_clond for buitin cmds
 * @cmd: cmd in quest
 * @us_input: user_input needed to be freed
 * @argv: Args prior to prog init(argv[0] == prog name for shel)
 * @cnt: counter
 * @cond: cond of exit
 */

void builtin_exit(char **cmd, char *us_input, char **argv, int cnt, int cond)
{
	int cond1, c = 0;

	if (cmd[1] == NULL)
	{
		free(us_input);
		free(cmd);
		exit(cond);
	}
	while (cmd[1][c])
	{
		if (_isalpha(cmd[1][c++]) != 0)
		{
			cust_err(argv, cnt, cmd);
			free(us_input);
			free(cmd);
			exit(2);
		}
		else
		{
			cond1 = _atoi(cmd[1]);
			if (cond1 == 2)
			{
				cust_err(argv, cnt, cmd);
				free(us_input);
				free(cmd);
				exit(cond1);
			}
			free(us_input);
			free(cmd);
			exit(cond1);
		}
	}
}
