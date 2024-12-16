/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:02 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/18 15:05:08 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_dup2(char *str, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	size += BUFFER_SIZE;
	dest = ft_calloc(sizeof(char), (size + 1));
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	while (i < size - BUFFER_SIZE)
	{
		dest[i] = str[i];
		i++;
	}
	free(str);
	return (dest);
}

char	*dupfinal(char *str)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(*str))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	dest = ft_calloc(sizeof(char), (i + 1 + (str[i] == '\n')));
	if (!dest)
		return (NULL);
	i = 0;
	while ((i == 0 || str[i - 1] != '\n') && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

long long	ft_strrchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	if (s[i] == c)
		return (i);
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
