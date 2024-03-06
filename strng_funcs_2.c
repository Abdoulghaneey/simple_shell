#include "shell.h"
/**
 * _strngcpy - cpy strng from sorce to dest
 * @destin: strng_destin
 * @sorce: strng_src
 * Return: destination
 */
char *_strngcpy(char *destin, char *sorce)
{
	int c = 0;

	while (sorce[c])
	{
		destin[c] = sorce[c];
		c++;
	}
	destin[c] = '\0';
	return (destin);
}
/**
 * _strcat - merging sorce ad dest strngs
 * @destin: strng destin
 * @sorce: strng sorce
 * Return: first string + second string
 */
char *_strcat(char *destin, char *sorce)
{
	char *ret = destin;

	while (*destin != '\0')
	{
		destin++;
	}

	while (*sorce != '\0')
	{
		*destin = *sorce;
		destin++;
		sorce++;
	}
	*destin = '\0';
	return (ret);
}
/**
 * _strngchr - searching for letter in a str
 * @strng: searched_str
 * @l: searched letter
 * Return: char ptr
 */
char *_strngchr(char *strng, char l)
{
	do {
		if (*strng == l)
		{
			break;
		}
	} while (*strng++);
	return (strng);
}
/**
 * _strncmp - compares str1 and str2 based on n chars
 * @strng1: strng1
 * @strng2: strng2
 * @n: size to compre
 * Return: 1 when they are same otherwise return 0
 */
int _strncmp(const char *strng1, const char *strng2, size_t n)
{
	size_t c;

	if (strng1 == NULL)
		return (-1);

	for (c = 0; c < n && strng2[c]; c++)
	{
		if (strng1[c] != strng2[c])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strngdup - strng_duplication
 * @strng: str in question
 * Return: Duplicate when successful
 */
char *_strngdup(char *strng)
{
	size_t len, c;
	char *strng2;

	len = _strlen(strng);
	strng2 = malloc(sizeof(char) * (len + 1));
	if (!strng2)
	{
		return (NULL);
	}
	for (c = 0; c <= len; c++)
	{
		strng2[c] = strng[c];
	}
	return (strng2);
}
