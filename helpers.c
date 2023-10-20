#include "main.h"
/**
 * _printf - yeb main
 * @str: constant char
 * Return: void
 */

void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
/**
 * free_array - yeb main
 * @array: char array
 * Return: void
 */

void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}
/**
 * split - yeb main
 * @d: data
 * @delim: constant char
 * Return: void
 */

void split(data *d, const char *delim)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->cmd, delim);
	while (token)
	{
		d->av = realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	d->av[ntoken] = NULL;
	return;
free:
	free_array(d->av);
	free(d->cmd);
	perror(d->shell_name);
	exit(EXIT_FAILURE);
}
/**
 * init_data - yeb main
 * @d: data
 * @shell_name: constant char
 * Return: void
 */

void init_data(data *d, const char *shell_name)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_name = shell_name;
	d->last_exit_status = EXIT_SUCCESS;
	d->flag_setenv = 0;
}
/**
 * read_cmd - yeb main
 * @d: data
 * Return: void
 */

void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nread - 1] = '\0';
	_trim(d->cmd);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[0] == '#' || (d->cmd[i] == '#' && d->cmd[i - 1] == ' '))
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	_trim(d->cmd);
}
