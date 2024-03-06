#include "shell.h"
/**
* _getline - showing what the user enters
* Return: buf input
*/
char *_getline()
{
	int c, rd, buf_size = BUFSIZE;
	char ch = 0, *bufer, *buf;

	bufer = malloc(buf_size);
	if (bufer == NULL)
	{
		free(bufer);
		return (NULL);
	}
	for (c = 0; ch != EOF && ch != '\n'; c++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &ch, 1);
		if (rd == 0)
		{
			free(bufer);
			exit(EXIT_SUCCESS);
		}
		bufer[c] = ch;
		if (bufer[0] == '\n')
			return (enter(bufer));
		if (c >= buf_size)
		{
			bufer = realloc(bufer, (buf_size + 2));
			if (bufer == NULL)
			{
				free(bufer);
				return (NULL);
			}
		}
	}
	bufer[c] = '\0';
	buf = space(bufer);
	free(bufer);
	hashtag_handler(buf);
	return (buf);
}
/**
 * enter - when enter is pressed
 * @str: Str in quest
 * Return: empty_str
 */
char *enter(char *str)
{
	free(str);
	return ("\0");
}

/**
 * space - treating whitesp before a str
 * @str: str in quest
 * Return: edited str
 */
char *space(char *str)
{
	int m, n = 0;
	char *bufer;

	bufer = malloc(sizeof(char) * (_strlen(str) + 1));
	if (bufer == NULL)
	{
		free(bufer);
		return (NULL);
	}
	for (m = 0; str[m] == ' '; m++)
		;
	for (; str[m + 1] != '\0'; m++)
	{
		bufer[n] = str[m];
		n++;
	}
	bufer[n] = '\0';
	if (bufer[0] == '\0' || bufer[0] == '#')
	{
		free(bufer);
		return ("\0");
	}
	return (bufer);
}
/**
 * hashtag_handler - rem all after hass tag
 * @bufer: buf inpu
 * Return: void
 */
void hashtag_handler(char *bufer)
{
	int c;

	for (c = 0; bufer[c] != '\0'; c++)
	{
		if (bufer[c] == '#' && bufer[c - 1] == ' ' && bufer[c + 1] == ' ')
		{
			bufer[c] = '\0';
		}
	}
}
