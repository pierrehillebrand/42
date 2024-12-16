/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:01 by lfarhi            #+#    #+#             */
/*   Updated: 2024/11/25 12:05:10 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	is_ok(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	in_echo(char **args, t_minishell *minishell)
{
	int	i;

	i = 1;
	while (args[i] && is_ok(args[i]))
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!is_ok(args[1]))
		ft_putchar_fd('\n', 1);
	(void)args;
	(void)minishell;
	return (EXIT_SUCCESS);
}
