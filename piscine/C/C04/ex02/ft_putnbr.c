/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:39:50 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/12 09:54:53 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(long int x)
{
	char	a;

	if (x != 0)
	{
		rec(x / 10);
		a = '0' + x % 10;
		write(1, &a, 1);
	}
}

void	ft_putnbr(int nb)
{
	long int	x;

	x = nb;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		rec(-x);
	}
	else
		rec(x);
}
