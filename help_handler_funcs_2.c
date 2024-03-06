#include "shell.h"
/**
 * env_help - show help msg on the shell via builtin cmd 'env'
 */
void env_help(void)
{
	char *info = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * help_setenv - show help msg via 'setenv' builtin cmd
 */
void help_setenv(void)
{
	char *info = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * unsetenv_help - show help msg via 'unsetenv' builtin cmd 'unsetenv'
 */
void unsetenv_help(void)
{
	char *info = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "message to stderr.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
/**
 * show_help - show help msg for  builtin cmds
 * @cmd: cmd in quest
 * @cond: cond of previously executed cmd
 * Return: 0 when successful
 */
int show_help(char **cmd, __attribute__((unused))int cond)
{
	if (!cmd[1])
		all_help();
	else if (_strngcmp(cmd[1], "alias") == 0)
		help_alias();
	else if (_strngcmp(cmd[1], "cd") == 0)
		cd_help();
	else if (_strngcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strngcmp(cmd[1], "env") == 0)
		env_help();
	else if (_strngcmp(cmd[1], "setenv") == 0)
		help_setenv();
	else if (_strngcmp(cmd[1], "unsetenv") == 0)
		unsetenv_help();
	else if (_strngcmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
