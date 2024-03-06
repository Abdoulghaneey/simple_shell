#include "shell.h"
/**
 * main - Start of shell prog
 * @argc: argc
 * @argv: Argv
 * Return: cond_ret
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *us_input, **cmd, **cmds;
	int cnt = 0, m, cond = 1, stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, treat_signal);
	while (cond)
	{
		cnt++;
		if (isatty(STDIN_FILENO))
			cmd_prompt();
		us_input = _getline();
		if (us_input[0] == '\0')
			continue;
		cmd_history(us_input);
		cmds = sep_cmds(us_input);
		for (m = 0; cmds[m] != NULL; m++)
		{
			cmd = parse_cmd(cmds[m]);
			if (_strngcmp(cmd[0], "exit") == 0)
			{
				free(cmds);
				builtin_exit(cmd, us_input, argv, cnt, stat);
			}
			else if (builtin_chk(cmd) == 0)
			{
				stat = builtin_handle(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, us_input, cnt, argv);
			free(cmd);
		}
		free(us_input);
		free(cmds);
		wait(&stat);
	}
	return (stat);
}
