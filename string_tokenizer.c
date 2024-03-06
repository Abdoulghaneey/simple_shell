#include "shell.h"
/**
 * delim_chk - Checking if any char matches
 * @ch: char in question
 * @str: delimeter strs
 * Return: 1 when successful otherwise 0
 */
unsigned int delim_chk(char ch, const char *str)
{
	unsigned int c;

	for (c = 0; str[c] != '\0'; c++)
	{
		if (ch == str[c])
			return (1);
	}
	return (0);
}
/**
 * _strtok - getting tokens from strs
 * @strng: strng in ques
 * @delim: delimiter
 * Return: next_tok pointre
 */
char *_strtok(char *strng, const char *delim)
{
	static char *toks;
	static char *tok_new;
	unsigned int c;

	if (strng != NULL)
		tok_new = strng;
	toks = tok_new;
	if (toks == NULL)
		return (NULL);
	for (c = 0; toks[c] != '\0'; c++)
	{
		if (delim_chk(toks[c], delim) == 0)
			break;
	}
	if (tok_new[c] == '\0' || tok_new[c] == '#')
	{
		tok_new = NULL;
		return (NULL);
	}
	toks = tok_new + c;
	tok_new = toks;
	for (c = 0; tok_new[c] != '\0'; c++)
	{
		if (delim_chk(tok_new[c], delim) == 1)
			break;
	}
	if (tok_new[c] == '\0')
		tok_new = NULL;
	else
	{
		tok_new[c] = '\0';
		tok_new = tok_new + c + 1;
		if (*tok_new == '\0')
			tok_new = NULL;
	}
	return (toks);
}
