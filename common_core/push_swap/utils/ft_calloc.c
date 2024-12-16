/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:02:25 by phillebr          #+#    #+#             */
/*   Updated: 2024/07/01 15:21:27 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(size * nbr);
	if (!dest)
		return (NULL);
	while (i < size * nbr)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
