#include "shell.h"
/**
 * _realloc -  This funcs is meant to allocate and free mem
 *@ptr: Target
 *@size_old: old ptr_size
 *@size_new: new ptr_size
 *Return: Aiming at realloc mem
 */
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
{
	void *ret_val;

	if (size_new == size_old)
		return (ptr);
	if (size_new == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	ret_val = malloc(size_new);
	if (ret_val == NULL)
	{
		free(ret_val);
		return (NULL);
	}
	if (ptr == NULL)
	{
		array_fill(ret_val, '\0', size_new);
		free(ptr);
	}
	else
	{
		_memcpy(ret_val, ptr, size_old);
		free(ptr);
	}
	return (ret_val);
}
/**
 * all_free - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void all_free(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
/**
 * _memcpy - move membytes from sorce to destin
 *@destin: destin
 *@sorce: sorce
 *@n: copied_size
 *Return: destin pointr
 */
char *_memcpy(char *destin, char *sorce, unsigned int n)
{
	unsigned int c;

	for (c = 0; c < n; c++)
	{
		destin[c] = sorce[c];
	}
	return (destin);
}
/**
 * array_fill - const byte arr fill
 *@ptr: pointing to nothing
 *@el: int
 *@len: int lenth
 *Return: void
 */
void *array_fill(void *ptr, int el, unsigned int len)
{
	char *p = ptr;
	unsigned int c = 0;

	while (c < len)
	{
		*p = el;
		p++;
		c++;
	}
	return (ptr);
}
/**
 * _calloc - malloc array
 *@s: size
 *Return: void pointer
 */
void *_calloc(unsigned int s)
{
	char *ptr;
	unsigned int c;

	if (s == 0)
	return (NULL);
	ptr = malloc(s);
	if (ptr == NULL)
	return (NULL);
	for (c = 0; c < s; c++)
	{
		ptr[c] = '\0';
	}
	return (ptr);
}
