#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - yeb main
 * @av: array of pointers
 * @cmd: char pointer
 * @shell_name: constant char
 * @last_exit_status: integral
 * @flag_setenv: integral
 */

typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} data;
/**
 * struct builtin - yeb main
 * @cmd: constant char
 * @f: void pointer
 */

typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;
/* builtin.c prototypes */
int exec_builtin(data *d);
void builtin_exit(data *d);
void builtin_env(data *d);
void builtin_setenv(data *d);
void builtin_unsetenv(data *d);
void builtin_cd(data *d);

/* helpers.c prototypes */
void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_name);
void read_cmd(data *d);

/* helpers2.c prototypes */
void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/* exec.c prototypes */
void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* path.c prototypes */
char *_getenv(char *name);
int _which(data *d);
int _setenv(data *d, char *name, char *value);

/* string_utils.c prototypes */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

/* string_utils2.c prototypes */
char *_strdup(const char *str);
int _isnumber(const char *status);
int _isdigit(int c);

/* _getline.c prototypes + buffer */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif /* MAIN_H */
