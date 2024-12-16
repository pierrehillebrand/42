/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:59:24 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/21 16:26:11 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	i = 0;
	len_little = ft_len(little);
	if (!len_little)
		return ((char *)(big));
	while (big[i] && i + len_little <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == len_little)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("HELLO WORLD", "", 3));
}
*/
