/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:05:19 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:31:42 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	return (i);
}

static int	check_dup(int *tab, int size)
{
	int	i;
	int	test;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		test = tab[i];
		while (i + j < size)
		{
			if (test == tab[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	tot;

	i = 0;
	tot = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (LONG_MIN);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = tot * 10 + (str[i] - '0');
		i++;
		if (tot > INT_MAX || tot < INT_MIN)
			return (tot * signe);
	}
	return (tot * signe);
}

int	*convert_int(char *str)
{
	int		*dest;
	int		i;
	int		nbr;
	long	test;

	i = 0;
	nbr = 0;
	dest = ft_calloc(count(str) + 1, sizeof(int));
	if (!dest)
		ft_clean_exit(str);
	i += space(str);
	while (str[i])
	{
		test = ft_atoi(str + i);
		if (test > INT_MAX || test < INT_MIN)
			return (free(str), ft_clean_exit(dest), NULL);
		dest[nbr++] = test;
		while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')
			|| str[i] == '+')
			i++;
		i += space(str + i);
	}
	if (!check_dup(dest, count(str)))
		return (free(str), ft_clean_exit(dest), NULL);
	return (free(str), dest);
}
