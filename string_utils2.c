#include "main.h"
/**
 * _strdup - yeb main
 * @str: constant char
 * Return: result
 */

char *_strdup(const char *str)
{
	int i, len = 0;
	char *result;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = str[i];

	return (result);
}
/**
 * _isnumber - yeb main
 * @status: constant char
 * Return: void
 */

int _isnumber(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}
/**
 * _isdigit - yeb main
 * @c: int
 * Return: 0, 1
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
