/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:26:54 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:06:55 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include "../minishell/minishell.h"
# include "../env/env.h"
# include <sys/wait.h>
# include <dirent.h>

typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

typedef struct s_tlist
{
	t_token			*content;
	struct s_tlist	*next;
}	t_tlist;

typedef struct main_args
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_main_args;

typedef struct s_minishell	t_minishell;

int		in_cd(char **args, t_minishell *minishell);
int		in_echo(char **args, t_minishell *minishell);
int		in_env(char **args, t_minishell *minishell);
void	test_create(t_minishell *minishell, int type);
int		in_exit(char **args, t_minishell *minishell);
void	print_sorted(char **export, char **vars);
char	**export(char *str, char **to_use);
int		in_export(char **args, t_minishell *minishell);
int		in_pwd(char **args, t_minishell *minishell);
int		unset(t_minishell *minishell, char *key, int type);
int		in_unset(char **args, t_minishell *minishell);
int		is_in(char *str, const char **args);
void	deal_with_signal(t_minishell *minishell);

t_tlist	*t_tlist_create(t_list *tokens);
void	error_open(char *path);
void	find_path(t_minishell *minishell, char **args);
void	free_args(char **args);
void	child(t_minishell *minishell, t_tlist *tokens, int fd_in, int fd_out);
int		*count(int *re, t_tlist *tokens);
void	redir_in_out(t_tlist *tokens, int *fds);
int		open_out(char *path, int type);
void	try_failure(t_tlist *tokens);
void	end_print(char **args, char **path);

char	*ft_strjoin_free(char *s1, char *s2);
void	exe(t_minishell *minishell, char **args, int type);

char	**get_args(t_tlist *exec);
int		exec_builtin(t_minishell *minishell, t_tlist **tokens);
void	close_test(int fd);

void	error_message(char *name, char *error);
void	clean_close(int *fds, int pipes, int i);
void	exec(t_minishell *minishell);

#endif