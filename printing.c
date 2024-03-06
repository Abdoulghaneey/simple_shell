#include "shell.h"

/**
 * num_print - num print
 * @num: printed_num
 */

void num_print(unsigned int num)
{
	unsigned int y = num;

	if ((y / 10) > 0)
		num_print(y / 10);

	_putchar(y % 10 + '0');
}

/**
 * num_print_int - int num print
 * @num: printed_num
 */

void num_print_int(int num)
{
	unsigned int z = num;

	if (num < 0)
	{
		_putchar('-');
		z = -z;
	}
	if ((z / 10) > 0)
		num_print(z / 10);

	_putchar(z % 10 + '0');
}

/**
 * echo_print - echo print
 * @cmd: cmd in question
 * Return: 0 Upon Success -1 Upon Failure
 */

int echo_print(char **cmd)
{
	pid_t pid;
	int cond;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &cond, WUNTRACED);
		} while (!WIFEXITED(cond) && !WIFSIGNALED(cond));
	}
	return (1);
}
