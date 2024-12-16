/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:25:23 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/31 13:18:18 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar(char c, t_keep keep)
{
	int	cur;

	cur = 0;
	while (cur + 1 < keep.min_width)
		cur += put_char(' ');
	cur += put_char(c);
	while (cur < keep.offset)
		cur += put_char(' ');
	return (cur);
}
