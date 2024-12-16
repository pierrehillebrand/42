/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:56:05 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/23 12:25:36 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_count(int n)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 1;
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	nbr;
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = ft_count(n);
	nbr = n;
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		nbr = -n;
		result[0] = '-';
	}
	while (i < count - (n < 0))
	{
		result[count - 1 - i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	result[count] = 0;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*dest = ft_itoa(0);

	if (dest)
	{
		printf("%s\n", dest);
		free(dest);
	}
	else
		printf("NULL");
}
*/
