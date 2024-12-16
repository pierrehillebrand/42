/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:30:45 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/20 17:10:42 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	mul;
	unsigned int	x;
	unsigned int	truc;

	mul = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		truc = -n;
	}
	else
		truc = n;
	if (truc == 0)
		write(fd, "0", 1);
	while (mul <= truc && mul < 1000000000)
		mul *= 10;
	if (mul < 1000000000 || truc < 1000000000)
		mul /= 10;
	while (mul > 0)
	{
		x = truc / mul + '0';
		write(fd, &x, 1);
		truc -= (truc / mul) * mul;
		mul /= 10;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
}
*/
