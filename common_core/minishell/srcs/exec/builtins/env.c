/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:03 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/04 18:57:08 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	test_create(t_minishell *minishell, int type)
{
	const char	*tab[] = {"/usr/bin/env", "/bin/env"};
	const char	*tab2[] = {"_=/usr/bin/env", "_=/bin/env"};

	if (get_var(minishell->env, "_").value)
		set_var(minishell->env, "_", (char *)tab[type]);
	else
	{
		minishell->env->vars = export((char *)tab2[type],
				minishell->env->vars);
		minishell->env->vars_len += 1;
		minishell->env->user = get_var(minishell->env, "USER");
		minishell->env->home = get_var(minishell->env, "HOME");
		minishell->env->path = get_var(minishell->env, "PATH");
	}
}

int	in_env(char **args, t_minishell *minishell)
{
	int		i;
	char	**env;

	test_create(minishell, 0);
	env = minishell->env->vars;
	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	(void)args;
	return (EXIT_SUCCESS);
}
