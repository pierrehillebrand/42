/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:03:26 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/22 10:18:57 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		alloc(int size, char **strs, char *sep);

char	*cat(char *s1, char *s2, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		tot_size;
	int		i;

	tot_size = alloc(size, strs, sep);
	if (size <= 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * tot_size);
	if (!str)
		return (NULL);
	str[0] = '\0';
	cat(str, strs[0], "");
	i = 1;
	while (i < size)
	{
		cat(str, strs[i], sep);
		i++;
	}
	return (str);
}

int	alloc(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	x;
	int	k;

	i = 0;
	x = 0;
	k = 0;
	while (sep[k] != '\0')
		k++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		x += j;
		i++;
	}
	if (size > 1)
		x += k * (size - 1) + 1;
	else
		x++;
	return (x);
}

char	*cat(char *s1, char *s2, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (sep[j] != '\0')
	{
		s1[i + j] = sep[j];
		j++;
	}
	i = i + j;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char *str;
	str = ft_strjoin(argc, argv, "\n");
	printf("%s\n", str);
	if (str)
		free (str);
	return (0);
}*/
