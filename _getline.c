#include <stdio.h>
#include <stdlib.h>
/**
 *_getline - get the arguments
 *@void: void
 *Return: arg buffer
 */
char *_getline(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;

	while ((nread = getline(&lineptr, &n, stdin)) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			printf("error in reading command");
			exit(EXIT_FAILURE);
		}
	}
	return (lineptr);
}
