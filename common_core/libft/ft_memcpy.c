/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:40:27 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/24 12:47:53 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_2;
	unsigned char	*truc;

	if (!dest && !src)
		return (NULL);
	dest_2 = (unsigned char *)(dest);
	truc = (unsigned char *)(src);
	i = 0;
	while (i < n)
	{
		dest_2[i] = truc[i];
		i++;
	}
	dest = (void *)(dest_2);
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	void	*c = NULL;
//	printf("%s\n", (char *)memcpy(c, c, 3));
	printf("%s\n", (char *)ft_memcpy(c, c, 3));
}
*/
