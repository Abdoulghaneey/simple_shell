#include "shell.h"
/**
 * _strngcmp - check if 2two strngs are same
 * @str1: str2
 * @str2: str2
 * Return: 0 when successful otherwise another thing
 */
int _strngcmp(char *str1, char *str2)
{
	int cmpre = 0, c, l1, l2;

	l1 = _strlen(str1);
	l2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);

	if (l1 != l2)
		return (1);

	for (c = 0; str1[c]; c++)
	{
		if (str1[c] != str2[c])
		{
			cmpre = str1[c] - str2[c];
			break;
		}
		else
			continue;
	}
	return (cmpre);
}
/**
 * _isalpha - checking alphabetic entry
 * @ch: letterin question
 * Return: 1 when true otherwise 0
 */
int _isalpha(int ch)
{
	if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _itoa - int to char converter
 * @n: int in question
 * Return: character ptr
 */
char *_itoa(unsigned int n)
{
	int l = 0, c = 0;
	char *str;

	l = intlen(n);
	str = malloc(l + 2);

	if (!str)
	{
		free(str);
		return (NULL);
	}
	*str = '\0';

	while (n / 10)
	{
		str[c] = (n % 10) + '0';
		n /= 10;
		c++;
	}

	str[c] = (n % 10) + '0';
	rev_arr(str, l);
	str[c + 1] = '\0';

	return (str);
}
/**
 * rev_arr - outut arr frm behind
 * @arr: arr in quest
 * @len: arr_len
 */
void rev_arr(char *arr, int len)
{
	int c;
	char tmp;

	for (c = 0; c < (len / 2); c++)
	{
		tmp = arr[c];
		arr[c] = arr[(len - 1) - c];
		arr[(len - 1) - c] = tmp;
	}
}
/**
 * intlen - getting int length
 * @n: int in question
 * Return: int_len
 */
int intlen(int n)
{
	int l = 0;

	while (n != 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}
