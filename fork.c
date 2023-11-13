#include "main.h"
/**
 * fork_and_execute - fork and execute command
 *
 * @command: user command
 *
 * Return: procees id.
 */
pid_t fork_and_execute(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/* Child process */
		char *args[MAX_INPUT_SIZE];
		int i = 0;
		char *token = strtok(command, " \t\n");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}
		args[i] = NULL;
		if (i > 0)
		{
			/* Execute the comand in the cchild process */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
				exit(1);
			}
		}
	}
	else if (pid < 0)
	{
		/* Erro handling for fork failure */
		perror("Erro:");
		exit(1);
	}
	/* Parent process returns the child PID */
	return (pid);
}
