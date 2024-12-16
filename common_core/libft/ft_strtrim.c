/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:51:14 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/23 13:13:47 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	calc(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s1[i] && is_in(s1[i], set) == 1)
		i++;
	while (s1[i + len])
		len++;
	len--;
	while (len > 0 && is_in(s1[i + len], set))
		len--;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	len = calc(s1, set);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && is_in(s1[i], set))
		i++;
	while (j < len)
	{
		dest[j] = s1[i + j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*dest = ft_strtrim("AAAV", "AV");

	printf("%s\n", dest);
	free(dest);
}
*/
