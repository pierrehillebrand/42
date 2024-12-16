/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:30:45 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/11 10:41:32 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(long nbr, int len_nbr)
{
	int		i;
	int		mul;
	char	c;

	mul = 1;
	i = 0;
	while (mul <= nbr && mul < 1000000000)
		mul *= 10;
	if (mul < 1000000000 || nbr < 1000000000)
		mul /= 10;
	while (mul > 1)
	{
		c = (nbr / mul) + '0';
		put_char(c);
		nbr -= (nbr / mul) * mul;
		mul /= 10;
	}
	c = nbr + '0';
	put_char(c);
	return (len_nbr);
}

static int	number_of_digit(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i + 1);
}

static int	get_values(int *total, int *len_prec, t_keep *keep, long *nl)
{
	int		len_nbr;
	int		truc;

	if (*nl < 0 || keep->plus || keep->space)
		keep->sign = 1;
	truc = keep->min_width;
	if (keep->size > truc)
		truc = keep->size;
	if (keep->offset > truc)
		truc = keep->offset;
	keep->size = truc - keep->sign;
	len_nbr = number_of_digit(*nl * (*nl > 0) + (*nl < 0) * -(*nl));
	*len_prec = len_nbr;
	if (keep->precision > len_nbr)
		*len_prec = keep->precision;
	if (!keep->dot)
		*len_prec = -1;
	*total += start(keep, nl, len_nbr, len_prec);
	return (len_nbr);
}

int	ft_putnum(long nl, t_keep keep)
{
	int	total;
	int	len_nbr;
	int	len_prec;
	int	i;
	int	test;

	i = 0;
	test = 0;
	total = 0;
	len_nbr = get_values(&total, &len_prec, &keep, &nl);
	if (nl != 0 || keep.precision > 0 || !keep.dot)
		total += putnbr(nl, len_nbr);
	else if (nl == 0 && keep.min_width && keep.precision <= 0)
		i += put_char(' ');
	while (keep.minus && total < keep.offset + test)
		total += put_char(' ');
	return (total);
}
