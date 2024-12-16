/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:27:47 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/09 12:54:48 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_builtin(t_minishell *minishell, t_tlist **tokens)
{
	int			i;
	char		**args;
	const char	*builtins[] = {"cd",
		"exit", "export", "unset", NULL};
	static int	(*built[])(char **args, t_minishell *minishell) = {in_cd,
		in_exit, in_export, in_unset};

	args = get_args(*tokens);
	if (!args)
		return (0);
	i = is_in(*args, builtins);
	if (i == 2 && (!args[1] || (!args[2] && !ft_strcmp(args[1], "--"))))
		return (free_args(args), 0);
	if (i != -1)
	{
		free(tokens);
		i = (*built[i])(args, minishell) * 256;
		(minishell->env->last_exit) = i;
		if (i < 0)
			return (minishell_free(minishell), free_args(args), exit(1), 1);
		return (free_args(args), 1);
	}
	free_args(args);
	return (0);
}
