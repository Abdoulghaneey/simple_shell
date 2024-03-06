#include "shell.h"
/**
 * path_cmd - checking for exec cmd
 * @cmd: cmd i question
 * Return: 0 when successful
 */
int path_cmd(char **cmd)
{
	char *p, *val, *p_cmd;
	struct stat buf;

	p = _envget("PATH");
	val = _strtok(p, ":");
	while (val != NULL)
	{
		p_cmd = build(*cmd, val);
		if (stat(p_cmd, &buf) == 0)
		{
			*cmd = _strngdup(p_cmd);
			free(p_cmd);
			free(p);
			return (0);
		}
		free(p_cmd);
		val = _strtok(NULL, ":");
	}
	free(p);
	free(val);
	return (1);
}
/**
 * build - constructing cmd
 * @tok: exec_cmd
 * @val: cmd_dir
 * Return: full_path of cmd when successfl otherwise return 0
 */
char *build(char *tok, char *val)
{
	char *cmd;
	size_t l;

	l = _strlen(val) + _strlen(tok) + 2;
	cmd = malloc(sizeof(char) * l);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, l);

	cmd = _strcat(cmd, val);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, tok);

	return (cmd);
}
/**
 * _envget - getting the env_var name
 * @env_n: env_var name
 * Return: env_var val otherwise NULL
 */
char *_envget(char *env_n)
{
	size_t len_n, len_v;
	char *val;
	int c, m, n;

	len_n = _strlen(env_n);
	for (c = 0 ; environ[c]; c++)
	{
		if (_strncmp(env_n, environ[c], len_n) == 0)
		{
			len_v = _strlen(environ[c]) - len_n;
			val = malloc(sizeof(char) * len_v);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			m = 0;
			for (n = len_n + 1; environ[c][n]; n++, m++)
			{
				val[m] = environ[c][n];
			}
			val[m] = '\0';

			return (val);
		}
	}
	return (NULL);
}
