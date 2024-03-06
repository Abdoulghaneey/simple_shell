#include "shell.h"
/**
 * change_dir - change_dir
 * @cmd: cmd in question
 * @cond: conditio of previosly executed cmd
 * Return: 0 when successful otherwise return 1
 * (For OLDPWD everytime 0 incase of no OLDPWD)
 */
int change_dir(char **cmd, __attribute__((unused))int cond)
{
	int val = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strngcmp(cmd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * show_env - Show env_var
 * @cmd: cmd in question
 * @s: cond of previously exec cmd
 * Return: 0 everytime
 */
int show_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int s)
{
	size_t c;
	int l;

	for (c = 0; environ[c] != NULL; c++)
	{
		l = _strlen(environ[c]);
		write(1, environ[c], l);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * builtin_echo - perform cases of echo
 * @cond: cond of previously exxec cmds
 * @cmd: cmd in question
 * Return: echo execution otherwise return 1
 */
int builtin_echo(char **cmd, int cond)
{
	char *pth;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		num_print_int(cond);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		num_print(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		pth = _envget("PATH");
		PRINT(pth);
		PRINT("\n");
		free(pth);
	}
	else
		return (echo_print(cmd));

	return (1);
}
/**
 * sh_history - show historical records of user inputs
 * @cmd: cmd in question
 * @s: status of last command executed
 * Return: 0 success or -1 if fail
 */
int sh_history(__attribute__((unused))char **cmd, __attribute__((unused))int s)
{
	char *fname = ".simple_shell_history";
	FILE *f_ptr;
	char *line = NULL;
	size_t l = 0;
	int c = 0;
	char *er;

	f_ptr = fopen(fname, "r");
	if (f_ptr == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &l, f_ptr)) != -1)
	{
		c++;
		er = _itoa(c);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(f_ptr);
	return (0);
}
