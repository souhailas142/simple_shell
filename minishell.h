#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>

extern char **environ;

int		_strcmp(char *str1, char *str2);
char	*_strdup(char *str);
int		_strlen(const char *string);
int		_printp(const char *prompt, unsigned int size);

int		verify_path(char **arguments);
char	*append_command(char *dir_path, char *command);
int		exec(char **arg);
int		fill_args(char *entry, char **arguments);
int		print_numbers(int n);
int		print_not_found(char **arguments, int counter);
char	*_getenv(char *global_var);
int		_putchar(char c);
int		exist(char *pathname);
void	free_grid(char **grid, int heigth);
void	last_free(char *entry);
int		verify_blt(char **arguments, int exit_stat);

#endif
