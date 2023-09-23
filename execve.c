#include "shell.h"

/**
 * is_executable - determines if is an executable
 *
 * @infosh: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(info_shell *infosh)
{
	struct stat st;
	int i;
	char *input;

	input = infosh->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	get_error(infosh, 127);
	return (-1);
}

/**
 * check_error - verifies if a  user has permissions to access
 *
 * @dir: destination directory
 * @infosh: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error(char *dir, info_shell *infosh)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(infosh->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * execmd - finds commands and executes
 *
 * @infosh: data structure
 * Return: 1 on success
 */
int execmd(info_shell *infosh)
{
	pid_t pid;
	pid_t wpid;
	int state;
	int command;
	char *dir;
	(void) wpid;

	command = is_executable(infosh);
	if (command == -1)
		return (1);
	if (command == 0)
	{
		dir = _which(infosh->args[0], infosh->_environ);
		if (check_error(dir, infosh) == 1)
			return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (command == 0)
			dir = _which(infosh->args[0], infosh->_environ);
		else
			dir = infosh->args[0];
		execve(dir + command, infosh->args, infosh->_environ);
	}
	else if (pid < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpid = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	infosh->status = state / 256;
	return (1);
}


