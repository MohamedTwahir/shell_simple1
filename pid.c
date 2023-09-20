#include "shell.h"


/**
 * main - Proces ID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	my_pid = getpid();
	write(STDOUT_FILENO, my_pid);
	return (0);

}
