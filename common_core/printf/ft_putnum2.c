/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:27:03 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/11 10:46:26 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_sign(t_keep *keep, long *nl, int len_nbr, int *len_prec)
{
	int			i;
	int			j;
	static int	test;

	test = 0;
	if (test)
		return (0);
	i = 0;
	j = 0;
	if (keep->plus && *nl >= 0)
		i += put_char('+');
	else if (keep->space && *nl >= 0)
		i += put_char(' ');
	if (*nl < 0)
	{
		i += put_char('-');
		*nl *= -1;
		keep->test = 1;
	}
	while (len_nbr + j++ < *len_prec)
		i += put_char('0');
	test++;
	return (i);
}

int	start(t_keep *keep, long *nl, int len_nbr, int *len_prec)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (!keep->minus)
	{
		if (!keep->dot)
		{
			if (keep->zero && keep->precision)
			{
				i += put_sign(keep, nl, len_nbr, len_prec);
				c = '0';
			}
			while (i + len_nbr < keep->size + (i > 0 && keep->test))
				i += put_char(c);
		}
		else
		{
			while (i + *len_prec < keep->size)
				i += put_char(c);
		}
	}
	i += put_sign(keep, nl, len_nbr, len_prec);
	return (i);
}
