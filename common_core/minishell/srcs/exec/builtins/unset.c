/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:15 by lfarhi            #+#    #+#             */
/*   Updated: 2024/11/22 16:20:10 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	unset(t_minishell *minishell, char *key, int type)
{
	int		i;
	char	**to;

	if (type)
		to = minishell->env->vars;
	else
		to = minishell->env->export;
	if (!to)
		return (0);
	i = 0;
	while (to[i] && ft_strcmp(key, to[i]) && ft_strcmp(to[i], key) != '=')
		i++;
	if (!to[i])
		return (0);
	else
	{
		free(to[i]);
		while (to[i + 1])
		{
			to[i] = to[i + 1];
			i++;
		}
		to[i] = NULL;
	}
	return (1);
}

int	in_unset(char **args, t_minishell *minishell)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (unset(minishell, args[i], 1))
			minishell->env->vars_len--;
		unset(minishell, args[i], 0);
		i++;
	}
	(void)args;
	(void)minishell;
	return (EXIT_SUCCESS);
}
