/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:21:33 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/09 16:55:39 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../minishell/minishell.h"

static int	count_occur(t_tlist *exec)
{
	int	i;
	int	token_switch;

	i = 0;
	token_switch = 0;
	while (exec && exec->content->type != PIPE)
	{
		if (exec->content->type == ARG && !token_switch)
			i++;
		if (exec->content->type == ARG)
			token_switch = 0;
		else
			token_switch = 1;
		exec = exec->next;
	}
	return (i);
}

char	**get_args(t_tlist *exec)
{
	int		i;
	int		token_switch;
	char	**args;

	if (!exec)
		return (NULL);
	i = count_occur(exec);
	args = ft_calloc(i + 1, sizeof(char *));
	if (!args || i == 0)
		return (free(args), NULL);
	i = 0;
	token_switch = 0;
	while (count_occur(exec))
	{
		if (exec->content->type == ARG && !token_switch)
		{
			args[i] = ft_strdup(exec->content->value);
			if (!args[i++])
				return (free_args(args), NULL);
		}
		token_switch = exec->content->type != ARG;
		exec = exec->next;
	}
	return (args);
}

static void	exec_child(t_minishell *minishell, t_tlist *tokens)
{
	char	**args;

	args = get_args(tokens);
	if (!args)
		return (minishell_free(minishell), exit(FAILURE));
	if (access(args[0], F_OK) == 0)
		exe(minishell, args, 1);
	find_path(minishell, args);
}

void	child(t_minishell *minishell, t_tlist *tokens, int fd_in, int fd_out)
{
	int	fds[2];

	fds[0] = fd_in;
	fds[1] = fd_out;
	minishell->env->in_child = 1;
	redir_in_out(tokens, fds);
	if (fds[0] < 0 || fds[1] < 0)
	{
		close_test(fd_in);
		close_test(fd_out);
		minishell_free(minishell);
		exit(1);
		return ;
	}
	dup2(fds[0], 0);
	dup2(fds[1], 1);
	close_test(fds[0]);
	close_test(fds[1]);
	exec_child(minishell, tokens);
}
