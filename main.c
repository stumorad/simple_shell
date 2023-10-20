#include "main.h"
/**
 * main - yeb main
 * @argc: argument counter
 * @argv: argument value
 * Return: 0
 */

int main(int argc, char **argv)
{
	data d;
	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);

	return (0);
}
