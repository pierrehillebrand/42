/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:52:50 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:24:16 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"

static int	putnbr_rec(unsigned long long int nb, int n)
{
	int	len;

	if (n--)
	{
		len = putnbr_rec(nb / 10, n);
		ft_putchar_fd((nb % 10) + '0', 1);
		return (len + 1);
	}
	return (0);
}

int	sp_putnbr_n(long long int nb, int n)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		return (putnbr_rec(-(unsigned long long int)nb, n - 1) + 1);
	}
	else
		return (putnbr_rec((unsigned long long int)nb, n));
}
