/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:00 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/23 13:15:47 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;
	size_t	len_t;

	len_t = 0;
	i = 0;
	s_len = 0;
	while (s[s_len])
		s_len++;
	while (start <= s_len && s[start + len_t] && len_t < len)
		len_t++;
	dest = malloc(sizeof(char) * (len_t + 1));
	if (!dest)
		return (NULL);
	while (i < len_t)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	char *x = ft_substr("tripouille", 100, 1);
	printf("%s\n", x);
	free(x);
}
*/
