/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:47:37 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/01 11:50:30 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_calloc(size_t size, size_t nbr)
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
