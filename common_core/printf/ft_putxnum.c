/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:05:20 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/11 11:02:37 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbrl;
	int				total;

	total = 0;
	nbrl = nbr;
	base_len = ft_strlen(base);
	if (nbrl >= base_len)
	{
		total += put_number_base(nbrl / base_len, base);
		total += put_number_base(nbrl % base_len, base);
	}
	else
	{
		total += put_char(base[nbrl]);
	}
	return (total);
}

static int	get_hex_size(int nbr)
{
	int				total;
	unsigned int	nbrl;

	total = 0;
	nbrl = nbr;
	if (nbrl >= 16)
	{
		total += get_hex_size(nbrl / 16);
		total += get_hex_size(nbrl % 16);
	}
	else
		total++;
	return (total);
}

static int	get_values(char	*prefix, int *len_prec, t_keep *keep, int nbr)
{
	int		len;

	len = get_hex_size(nbr);
	*len_prec = len;
	if (keep->precision > len)
		*len_prec = keep->precision;
	*prefix = '0';
	if (keep->zero && keep->dot && keep->size > keep->precision)
		*prefix = ' ';
	if (!keep->zero)
		*prefix = ' ';
	if (keep->zero)
		keep->min_width = keep->size;
	if (keep->precision > keep->min_width)
		keep->min_width = keep->precision;
	if (keep->sharp && nbr != 0)
		keep->min_width -= 2;
	return (len);
}

static int	put_x(int is_maj, int len, int nbr, t_keep keep)
{
	int	total;

	total = 0;
	if (nbr == 0 && keep.min_width && keep.min_width < len)
		total += put_char(' ');
	else if (nbr == 0 && keep.dot && !keep.precision && keep.min_width >= len)
		total += put_char(' ');
	else if (!(nbr == 0 && keep.dot && !keep.precision))
	{
		if (is_maj)
			total += put_number_base(nbr, "0123456789ABCDEF");
		else
			total += put_number_base(nbr, "0123456789abcdef");
	}
	return (total);
}

int	ft_putxnum(int nbr, int is_maj, t_keep keep)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &keep, nbr);
	while (len_prec + total < keep.min_width)
		total += put_char(prefix);
	if (keep.sharp && nbr != 0)
	{
		if (is_maj)
			total += put_str("0X");
		else
			total += put_str("0x");
	}
	while (len + total < keep.min_width + ((keep.sharp && nbr != 0) * 2))
		total += put_char('0');
	total += put_x(is_maj, len, nbr, keep);
	while (total < keep.offset)
		total += put_char(' ');
	return (total);
}
