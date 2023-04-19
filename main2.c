#include "main.h"

int token_counter(char *token);

int main(int agrc, char *argv[])
{
	char *command = NULL;
	char *delim = " ";
	char *token;
	int i, token_count = 0;
	size_t n = 10;
	pid_t pid;
	ssize_t num_of_char;

	while (1)
	{
		printf("Shell $ ");
		num_of_char = getline(&command, &n, stdin);

		if (num_of_char == -1)
		{
			return (-1);
		}

		token = strtok(command, delim);

		i = 1;

		while(token)
		{
			token_count = token_counter(token);
			switch (token_count)
			{
				case 'A':
					break;
				default:
					printf("%s: No such file or directory", token);
			}
			printf("Token %d: %s", i++, token);
			token = strtok(NULL, delim); 
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
		else if (pid == 0)
		{
			exit (0);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}

int token_counter(char *token)
{
	int count = 0, i;

	while (token[i] != '\0')
	{
		count = count + token[i - 0];
	}
	return (count);
}
