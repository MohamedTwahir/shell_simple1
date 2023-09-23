#include "shell.h"

/**
 * delete_comment - deletes comments from the input
 *
 * @ingiza: input string
 * Return: input with no comments
 */
char *delete_comment(char *ingiza)
{
	int i, hadi;

	hadi = 0;
	for (i = 0; ingiza[i]; i++)
	{
		if (i == 0)
		{
			if (ingiza[i] == '#')
			{
				free(ingiza);
				return (NULL);
			}
			if (ingiza[i - 1] == '' || ingiza[i - 1] == '\t' || ingiza[i - 1] == ';')
				hadi = i;
		}
	}
	if (hadi != 0)
	{
		ingiza = _realloc(ingiza, hadi + 1);
		ingiza[hadi] = '\0';
	}

	return (ingiza);
}

/**
 * loop - loop for the shell
 * store: data relevant (av, input, args)
 *
 * Return: no return
 */
void loop(info_shell *infosh)
{
	int looper, reader;
	char *input;

	looper = 1;
	while (looper == 1)
	{
		write(STDIN_FILENO, "#cisfun$", 4);
		input = line_reader(&reader);
		if (reader != -1)
		{
			input = delete_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(storage, input) == 1)
			{
				infosh->status = 2;
				free(input);
				continue;
			}
		}
		input = rep_var(input, storage);
		looper = split_commands(storage, input);
		infosh->counter += 1;
		free(input);
	}
	else
	{
		looper = 0;
		free(input);
	}
}
