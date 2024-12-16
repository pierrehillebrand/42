/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:15:20 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/11 10:37:56 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_keep(t_keep *keep)
{
	keep->sharp = 0;
	keep->space = 0;
	keep->plus = 0;
	keep->minus = 0;
	keep->min_width = 0;
	keep->dot = 0;
	keep->precision = 0;
	keep->zero = 0;
	keep->size = 0;
	keep->offset = 0;
	keep->test = 0;
	keep->sign = 0;
}

int	ft_atoii(const char *str, int *count)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		(*count)++;
	}
	return (num);
}

int	in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

int	put_number(long nl)
{
	int		total;
	long	num;	

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += put_char('-');
		num = -nl;
	}
	if (num > 100)
		total += put_number(num / 10);
	else if (num == 100)
		total += put_str("10");
	else if ((num / 10) > 0)
		total += put_char((num / 10) + '0');
	total += put_char((num % 10) + '0');
	return (total);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
