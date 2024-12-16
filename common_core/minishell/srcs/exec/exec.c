/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:26:47 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:05:43 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	get_pipes(t_tlist *tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return (-1);
	while (tokens)
	{
		if (((t_token *)tokens->content)->type == PIPE)
			i++;
		tokens = tokens->next;
	}
	return (i);
}

static t_tlist	**split_pipes(t_tlist *tokens, int pipes)
{
	int		i;
	t_tlist	**tokens_list;
	t_tlist	*temp;

	if (!tokens)
		return (NULL);
	tokens_list = ft_calloc(pipes + 2, sizeof(t_tlist *));
	if (!tokens_list)
		return (free(tokens), NULL);
	i = 1;
	tokens_list[0] = tokens;
	while (i < pipes + 1)
	{
		if (tokens->next->content->type == PIPE)
		{
			temp = tokens->next;
			temp = temp->next;
			tokens_list[i++] = temp;
			tokens = temp;
		}
		else
			tokens = tokens->next;
	}
	return (tokens_list);
}

static void	clean(t_minishell *minishell, pid_t *pid, t_tlist **tokens)
{
	free(tokens);
	free(pid);
	minishell_free(minishell);
}

static void	pipe_exec(t_minishell *minishell,
int pipes, pid_t *pid, t_tlist **tokens)
{
	int		i;
	int		*fds;
	t_tlist	*test;

	catch_signal(2);
	i = -1;
	fds = ft_calloc((pipes + 2) * 2, sizeof(int));
	if (!fds)
		return (clean(minishell, pid, tokens), exit(FAILURE));
	fds[pipes * 2 + 3] = 1;
	while (++i < pipes + 1)
	{
		if (i != pipes)
			if (pipe(fds + ((i + 1) * 2)) < 0)
				return (clean(minishell, pid, tokens), free(fds), exit(1));
		pid[i] = fork();
		if (pid[i] == 0)
			return (close_test(fds[i * 2 + 2]), free(pid), test = tokens[i],
				pipes = fds[i * 2], i = fds[i * 2 + 3], free(tokens),
				free(fds), child(minishell, test, pipes, i));
		clean_close(fds, pipes, i);
	}
	return (free(fds));
}

void	exec(t_minishell *minis)
{
	int		pipes;
	pid_t	*pid;
	t_tlist	**tokens;
	int		i;

	catch_signal(0);
	i = -1;
	pipes = get_pipes(t_tlist_create(minis->lexer->tokens));
	if (pipes < 0)
		return (minishell_free(minis), exit(FAILURE));
	tokens = split_pipes(t_tlist_create(minis->lexer->tokens), pipes);
	if (!tokens)
		return (minishell_free(minis), exit(FAILURE));
	if (pipes == 0)
		if (exec_builtin(minis, tokens))
			return (catch_signal(1));
	pid = ft_calloc(pipes + 2, sizeof(pid_t));
	if (!pid)
		return (catch_signal(1), minishell_free(minis), free(tokens), exit(1));
	pipe_exec(minis, pipes, pid, tokens);
	while (++i < pipes + 1)
		waitpid(pid[i], &minis->env->last_exit, 0);
	deal_with_signal(minis);
	return (free(tokens), free(pid), catch_signal(1));
}
