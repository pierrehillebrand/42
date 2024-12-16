/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:12:20 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/03 16:12:05 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_long_as_hex(long unsigned addr)
{
	char		c;
	int			total;
	const char	*hex = "0123456789abcdef";

	total = 0;
	if (addr >= 16)
	{
		total += put_long_as_hex(addr / 16);
		total += put_long_as_hex(addr % 16);
	}
	else
	{
		c = hex[(addr % 16)];
		write(1, &c, 1);
		total++;
	}
	return (total);
}

static int	get_hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += get_hex_size(addr / 16);
		total += get_hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

static int	null(t_keep keep)
{
	int	len;
	int	total;

	len = 5;
	total = 0;
	while (len + total < keep.min_width)
		total += put_char(' ');
	total += put_str("(nil)");
	while (total < keep.offset)
		total += put_char(' ');
	return (total);
}

int	ft_putpointer(void *ptr, t_keep keep)
{
	long	addr;
	int		total;
	int		len;

	if (!ptr)
		return (null(keep));
	addr = (long unsigned)ptr;
	total = 0;
	len = get_hex_size(addr) + 2;
	while (len + total < keep.min_width)
		total += put_char(' ');
	total += put_str("0x");
	total += put_long_as_hex(addr);
	while (total < keep.offset)
		total += put_char(' ');
	return (total);
}
