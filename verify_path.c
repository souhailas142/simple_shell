#include "minishell.h"
/**
 * verify_path - Verify if the first command can be executed
 * @args: Array of entries by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int verify_path(char **args)
{
	char	*globl_path = NULL;
	char	*global_dup = NULL;
	char	*dir_path = NULL;
	char	*command_path = NULL;
	char	*test_cph[121];
	int exist_stat = -1, i = 0;

	globl_path = _getenv("PATH");
	if (globl_path == NULL)
		return (-1);
	global_dup = (_strdup(globl_path));
	dir_path = strtok(global_dup, ":");
	if (dir_path == NULL)
		return (-1);
	free(globl_path);
	while (exist_stat == -1 && dir_path != NULL)
	{
		command_path = append_command(dir_path, args[0]);
		test_cph[i] = command_path;
		exist_stat = exist(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(global_dup);
	free_grid(test_cph, i);
	if (exist_stat == 0)
	{
		args[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}
