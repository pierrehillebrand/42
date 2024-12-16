/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:06 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/05 15:32:21 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	ft_atoi_test(const char *nptr, int *error)
{
	unsigned long long	value;
	long				neg;
	unsigned long long	temp;
	unsigned long long	fence;

	fence = LLONG_MAX;
	value = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		temp = value;
		value = (value * 10) + (*(nptr++) - '0');
		if (temp > value || (value > 0 && value -1 - (neg == -1) >= fence))
			*error = 1;
	}
	return ((int)(value * neg));
}

static int	str_is_num(char *str)
{
	int	i;
	int	error;

	error = 0;
	ft_atoi_test(str, &error);
	if (error)
		return (0);
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	in_exit(char **args, t_minishell *minishell)
{
	int	test;

	if (!minishell->env->in_child)
		ft_putstr_fd("exit\n", 1);
	if (!args[1])
	{
		test = minishell->env->last_exit / 256;
		free_args(args);
		return (minishell_free(minishell), exit(test), 1);
	}
	else if (!str_is_num(args[1]))
		return (ft_putstr_fd("exit: ", 2),
			error_message(args[1], ": numeric argument required\n"),
			free_args(args), minishell_free(minishell), exit(2), 1);
	else if (args[2])
		return (ft_putstr_fd("exit: too many arguments\n", 2),
			free_args(args), minishell_free(minishell), exit(1), 1);
	else
	{
		test = ft_atoi(args[1]);
		free_args(args);
		minishell_free(minishell);
		exit (test % 256);
	}
	return (args[2] != NULL);
}
