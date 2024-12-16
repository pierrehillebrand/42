/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:29:33 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/24 12:34:54 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	tab = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		if (tab[i] == (unsigned char)(c % 256))
			return ((void *)(tab + i));
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%s\n", (char *)memchr("/|\x12\xff\x09\x42\2002\42|\\", '\200', 10));
	printf("%s\n", (char *)ft_memchr("/|\x12\xff\x09\x42\2002\42|\\", '\200', 10));
}
*/
