/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:31:58 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:23:09 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"
#include <linux/limits.h>

static void	cd_pwd(char **args, t_minishell *minishell)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
		set_var(minishell->env, "PWD", args[1]);
	else
		set_var(minishell->env, "PWD", str);
	free(str);
}

static int	normal(char **args, t_minishell *minishell)
{
	char	*str;
	size_t	test;
	char	*tab[3];

	str = getcwd(NULL, 0);
	if (!str)
		ft_putstr_fd("chdir: error retrieving current directory: getcwd: \
cannot access parent directories: No such file or directory\n", 2);
	free(str);
	if (chdir(args[1]) < 0)
		return (ft_putstr_fd("cd: ", 2), perror(args[1]), 1);
	if (find_var_line(minishell->env, "PWD", &test))
	{
		set_var(minishell->env, "OLDPWD", get_var(minishell->env, "PWD").value);
		cd_pwd(args, minishell);
		return (0);
	}
	tab[1] = "OLDPWD";
	tab[2] = NULL;
	in_unset(tab, minishell);
	return (0);
}

int	in_cd(char **a, t_minishell *minishell)
{
	char	*str;
	char	*home[2];

	if (!a[1])
	{
		str = get_var(minishell->env, "HOME").value;
		if (!str)
			return (ft_putstr_fd("cd: HOME not set\n", 2), 1);
		return (home[1] = str, normal(home, minishell));
	}
	else if (a[2])
		return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
	else
	{
		if (a[1][0] == '-' && a[1][1])
			return (a[1][2] = 0, ft_putstr_fd("cd: ", 2), error_message(a[1],
			": invalid option\ncd: usage: cd [-L|[-P [-e]] [-@]] [dir]\n"), 2);
		if (ft_strlen(a[1]) > PATH_MAX - 1)
			return (ft_putstr_fd("cd:", 2),
				error_message(a[1], ": File name too long\n"), 1);
		return (normal(a, minishell));
	}
	return (0);
}
