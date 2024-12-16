/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:25:23 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/03 11:50:31 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static int	put_str_size(char *str, int size, t_keep keep, int truc)
{
	int	i;

	if (keep.precision != -1)
	{
		while (truc + keep.precision < keep.min_width)
			truc += put_char(' ');
	}
	if (size == -1)
		return (put_str(str));
	i = 0;
	while (str[i] && i < size)
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putstr(char *str, t_keep keep)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		len = 6 * (keep.dot == 0 || (keep.dot && keep.precision >= 6));
	else
		len = ft_strlen(str);
	while (i + len < keep.min_width)
		i += put_char(' ');
	if (!keep.dot)
		keep.precision = -1;
	if (!str && keep.dot && keep.precision < 6)
		i += put_str_size("", keep.precision, keep, i);
	else if (!str)
		i += put_str_size("(null)", keep.precision, keep, i);
	else
		i += put_str_size(str, keep.precision, keep, i);
	while (i < keep.offset)
		i += put_char(' ');
	return (i);
}
