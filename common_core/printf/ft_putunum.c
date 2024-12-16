/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:30:45 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/31 14:58:00 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unumber(unsigned long nl)
{
	int				total;
	unsigned long	num;	

	total = 0;
	num = nl;
	if (num > 100)
		total += put_unumber(num / 10);
	else if (num == 100)
		total += put_str("10");
	else if ((num / 10) > 0)
		total += put_char((num / 10) + '0');
	total += put_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(unsigned long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char	*prefix, int *lp, t_keep *keep, unsigned long num)
{
	int	len;

	len = number_of_digit(num);
	*lp = len;
	if (keep->precision > len)
		*lp = keep->precision;
	*prefix = '0';
	if (keep->zero && keep->dot && keep->size > keep->precision)
		*prefix = ' ';
	if (!keep->zero)
		*prefix = ' ';
	if (keep->zero)
		keep->min_width = keep->size;
	if (keep->precision > keep->min_width)
		keep->min_width = keep->precision;
	return (len);
}

static int	put_u(int len, unsigned long num, t_keep keep)
{
	int	total;

	total = 0;
	if (num == 0 && keep.min_width && keep.min_width < len)
		total += put_char(' ');
	else if (num == 0 && keep.dot && !keep.precision && keep.min_width >= len)
		total += put_char(' ');
	else if (!(num == 0 && keep.dot && !keep.precision))
		total += put_unumber(num);
	return (total);
}

int	ft_putunum(unsigned long num, t_keep keep)
{
	int		total;
	int		len;
	int		len_prec;
	char	prefix;

	total = 0;
	len = get_values(&prefix, &len_prec, &keep, num);
	while (len_prec + total < keep.min_width)
		total += put_char(prefix);
	while (len + total < keep.min_width)
		total += put_char('0');
	total += put_u(len, num, keep);
	while (total < keep.offset)
		total += put_char(' ');
	return (total);
}
