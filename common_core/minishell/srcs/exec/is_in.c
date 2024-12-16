/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:52:34 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:39 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	deal_with_signal(t_minishell *minishell)
{
	if (g_last_signal)
	{
		minishell->env->last_exit = (128 + g_last_signal) * 256;
		if (g_last_signal == 2)
			ft_putstr_fd("\n", 2);
		else if (g_last_signal == 3)
			ft_putstr_fd("Quit (core dumped)\n", 2);
	}
}

void	try_failure(t_tlist *tokens)
{
	int	temp;

	while (tokens)
	{
		if (tokens->content->type > 1 && tokens->content->type < 4)
		{
			temp = open_out(tokens->next->content->value,
					tokens->content->type * 3);
			close_test(temp);
		}	
		tokens = tokens->next;
	}
}

int	is_in(char *str, const char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(str, args[i]))
			return (i);
		i++;
	}
	return (-1);
}
