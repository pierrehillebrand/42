/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:06:04 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:24:24 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"

int	sp_sizeof_nb_base(unsigned long long int nb, unsigned int base_len)
{
	int	len;

	len = 0;
	if (nb >= base_len)
		len += sp_sizeof_nb_base(nb / base_len, base_len) + 1;
	else
		len++;
	return (len);
}

int	sp_putnbr_base(unsigned long long int nb,
	char *base, unsigned int base_len)
{
	int	len;

	len = 0;
	if (nb >= base_len)
	{
		len += sp_putnbr_base(nb / base_len, base, base_len) + 1;
		ft_putchar_fd(base[nb % base_len], 1);
	}
	else
	{
		len++;
		ft_putchar_fd(base[nb % base_len], 1);
	}
	return (len);
}
