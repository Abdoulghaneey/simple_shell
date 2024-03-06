#include "shell.h"

/**
 * read_file - This reads arg_files for cmds
 * @cmd_file: doc which has cmds
 * @argv: parsed_args
 * Return: 0 otherwise return -1
 */

void read_file(char *cmd_file, char **argv)
{
	FILE *f_pt;
	char *line = NULL;
	size_t len = 0;
	int c = 0;

	f_pt = fopen(cmd_file, "r");
	if (f_pt == NULL)
	{
		file_err(argv, c);
		exit(127);
	}
	while ((getline(&line, &len, f_pt)) != -1)
	{
		c++;
		handle_file(line, c, f_pt, argv);
	}
	if (line)
		free(line);
	fclose(f_pt);
	exit(0);
}

/**
 * handle_file - resolve cmds and exec
 * @line: file_line
 * @c: counting the err
 * @f_pt: file_ptr
 * @argv: args of cmd line
 */

void handle_file(char *line, int c, FILE *f_pt, char **argv)
{
	char **cmd;
	int cond = 0;

	cmd = parse_cmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bool_file(cmd, line, f_pt);
	else if (builtin_chk(cmd) == 0)
	{
		cond = builtin_handle(cmd, cond);
		free(cmd);
	}
	else
	{
		cond = check_cmd(cmd, line, c, argv);
		free(cmd);
	}
}

/**
 * exit_bool_file - exitinginput file
 * @line: file_line
 * @cmd: cmd_parsed
 * @fd: File Descriptor
 */

void exit_bool_file(char **cmd, char *line, FILE *fd)
{
	int cond;
	int c = 0;

	if (cmd[c] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][c])
	{
		if (_isalpha(cmd[1][c++]) < 0)
			perror("Illegal number");
	}
	cond = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(cond);
}
