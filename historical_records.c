#include "shell.h"
/**
 * cmd_history - Past user cmds
 * @us_input: user_inp
 * Return: 0 when successful otherwise -1
 */
int cmd_history(char *us_input)
{
	char *fname = ".simple_shell_history";
	ssize_t fd, ret_wr;
	int len = 0;

	if (!fname)
		return (-1);
	fd = open(fname, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (us_input)
	{
		while (us_input[len])
			len++;
		ret_wr = write(fd, us_input, len);
		if (ret_wr < 0)
			return (-1);
	}
	return (1);
}
