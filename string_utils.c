#include "main.h"
/**
 * _strlen - yeb main
 * @str: char
 * Return: i
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _strcmp - yeb main
 * @s1: constant char
 * @s2: constant char
 * Return: 0, -, +
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}
/**
 * _strncmp - yeb main
 * @s1: constant char
 * @s2: constant char
 * @n: int
 * Return: 0, -, +
 */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}
/**
 * _strcpy - yeb main
 * @dest: char
 * @src: constant char
 * Return: @dest
 */

char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}
/**
 * _strcat - yeb main
 * @dest: char
 * @src: constant char
 * Return: result
 */

char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
