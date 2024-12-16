/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:49:28 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/24 12:48:52 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_2;
	char	*src_2;

	dest_2 = (char *)(dest);
	src_2 = (char *)(src);
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (i < n)
		{
			dest_2[i] = src_2[i];
			i++;
		}
	}
	while (i < n)
	{
		dest_2[n - 1 - i] = src_2[n - 1 - i];
		i++;
	}
	dest = (void *)(dest_2);
	return (dest);
}
