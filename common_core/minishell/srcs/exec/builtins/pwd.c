/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:12 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 15:25:23 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	in_pwd(char **args, t_minishell *minishell)
{
	char	*str;
	char	*arg;

	arg = args[1];
	if (arg && arg[0] == '-' && arg[1])
		return (arg[2] = 0, ft_putstr_fd("pwd: ", 2),
			error_message(arg, ": invalid option\npwd: usage: pwd [-LP]\n"), 2);
	str = getcwd(NULL, 0);
	if (!str)
		return (ft_putstr_fd("pwd: error retrieving current directory: getcwd: \
cannot access parent directories: No such file or directory\n", 2), 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
	(void)(args);
	(void)(minishell);
	return (EXIT_SUCCESS);
}
