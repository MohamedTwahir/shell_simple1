#include "shell.h"

/**
 * data_freer - makes the data structure created free
 *
 * @infosh: the data structure
 * Return: no return
 */
void data_freer(info_shell *infosh)
{
	unsigned int i;

	for (i = 0; infosh->_environ[i]; i++)
	{
		free(infosh->_environ[i]);
	}
	free(infosh->_environ);
	free(infosh->pid);
}

/**
 * data_setter - Initializes the data structure
 *
 * @infosh: data structure initialized
 * @av: argument vector
 * Return: no return
 */

void data_setter(info_shell *infosh, char **av)
{
	unsigned int i;


	infosh->counter = 1;
	infosh->status = 0;
	infosh->av = av;
	infosh->input = NULL;
	infosh->args = NULL;

	size_t i;

	for (i = 0; environ[i]; i++)
	{

	}
	datash->_environ = (char **)malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		infosh->_environ[i] = _strdup(environ[i]);
	}

	infosh->_environ[i] = NULL;
	infosh->pid = getpid();

/**
 * main - Starting  point for the program
 *
 * @ac: argument for  counting
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	info_shell infosh;
	(void) ac;

	signal(SIGINT, get_signt);
	data_setter(&infosh, av);
	loop(&infosh);
	data_freer(&infosh);
	if (infosh.status < 0)
	{
		return (255);
	}
	else
	{
		return (infosh.status);
	}
