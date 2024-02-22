/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:41:26 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/08 09:30:24 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(int a);

void	ft_putnbr(int nb)
{
	if (nb > 0)
	{
		rec(nb);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		write(1, "-", 1);
		nb = nb * (-1);
		rec(nb);
	}
}

void	rec(int a)
{
	char	x;

	if (a != 0)
	{
		x = a % 10 + '0';
		rec(a / 10);
		write(1, &x, 1);
	}
}
