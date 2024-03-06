#include "main.h"
/**
 * get_op_func - a function for print character
 * specifier
 * @s: string pointer
 * Return: pointer to a funtion
 */
int (*get_op_func(const char *s))(char **)
{
	int i, p, k = 0;
	op_t ops[] = {
		{"cd", lsh_cd},
		{"help", lsh_help},
		{"exit", lsh_exit},
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].op != NULL)
	{
		for (p = 0; s[p] != '\0'; p++)
		{
			if (s[p] == *(ops[i].op + p))
				k++;
		}
		if (k == p)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}
