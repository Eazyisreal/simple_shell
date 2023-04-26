#include "shell.h"

/**
 * exit_arg - handles exiting out of shell
 *
 * @cmd: holds an array of user-entered command
 * @argv: holds an array of user entered arguments
 * @buffer: command entered
 *
 * Return: int
 */

int exit_arg(char **cmd, char **argv, char *buffer)
{
	int status = _atoi(cmd[1]);

	if (status < 0 || (status == 0 && cmd[1][0] != '0'))
	{
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": 1: exit: Illegal number: ", 27);
		write(2, cmd[1], _strlen(cmd[1]));
		write(2, "\n", 1);
		free(buffer);
		exit(2);
	}

	free(buffer);
	exit(status);
}
