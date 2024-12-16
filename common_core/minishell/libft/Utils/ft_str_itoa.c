/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:15:05 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/02 15:29:07 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_itoa(int n, char *res)
{
	int		len;
	int		n_len;

	len = n <= 0;
	n_len = n;
	while (n_len != 0)
	{
		n_len /= 10;
		len++;
	}
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		res[--len] = ((-(long long)n) % 10) + '0';
		n = -(n / 10);
	}
	while (len-- && n != 0)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (len);
}
