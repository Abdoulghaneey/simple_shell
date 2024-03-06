#include "shell.h"

/**
 * env_create - This creates env_var array
 * @env: storage of array of env_var
 */

void env_create(char **env)
{
	int c;

	for (c = 0; environ[c]; c++)
		env[c] = _strngdup(environ[c]);
	env[c] = NULL;
}

/**
 * env_free - This clears the env_var array
 * @env:  storage of array of env_var
 */

void env_free(char **env)
{
	int c;

	for (c = 0; env[c]; c++)
	{
		free(env[c]);
	}
}
