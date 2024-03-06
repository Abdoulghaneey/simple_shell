#include "shell.h"
/**
 * _putchar - This function output char
 * @ch: printed char
 * Return: ch
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
/**
 * _putstrng - The func outut strs
 * @strng: str pointer
 * Return: nothing
 */
void _putstrng(char *strng)
{
	int c;

	for (c = 0; strng[c] != '\0'; c++)
	{
		_putchar(strng[c]);
	}
	_putchar('\n');
}
/**
 * _strncpy - copying a number of strng
 * @destin: str_destin
 * @sorce: str_sorce
 * @n: size of chars to cpy
 * Return: strng_copied
 */
char *_strncpy(char *destin, char *sorce, int n)
{
	int c = 0;

	while (c < n && *(sorce + c))
	{
		*(destin + c) = *(sorce + c);
		c++;
	}
	while (c < n)
	{
		*(destin + c) = '\0';
		c++;
	}
	return (destin);
}
/**
 * _strlen - size of the strng
 * @strng: input_str
 * Return: str_length
 */
int _strlen(char *strng)
{
	int c;

	for (c = 0; strng[c] != '\0'; c++)
	{
		continue;
	}
	return (c);
}
/**
 * _atoi - Strng to Int conversion
 * @strng: strng in question
 * Return: int
 */
int _atoi(char *strng)
{
	int m = 0, n = 1, k;
	unsigned int c = 0;

	while (strng[m] != '\0')
	{
		if (strng[m] == '-')
		{
			return (2);
		}
		k = strng[m] - '0';

		if (c > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			c = c * 10 + k;

		m++;
	}
	c *= n;
	return (c);
}
