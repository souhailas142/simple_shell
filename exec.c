#include "minishell.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arg: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arg)
{
	pid_t pid = 0;
	int stat = 0, exe_stat = 0;

	pid = fork();
	if (pid == -1)
		_printp("failed\n", 7);
	else if (pid == 0)
	{
		exe_stat = execve(arg[0], arg, environ);
		if (exe_stat == -1)
		{
			exe_stat = 126;
			perror("hsh");
			exit(exe_stat);
		}
		exit(0);
	}
	else
		wait(&stat);
	exe_stat = WEXITSTATUS(stat);
	return (exe_stat);
}
