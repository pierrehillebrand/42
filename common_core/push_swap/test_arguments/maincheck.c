/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:51:33 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:25:35 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (i + j < size)
		{
			if (tab[i] >= tab[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] && (str[i] == 32 || str[i] == '-' || str[i] == '+'))
			i++;
	}
	return (nb);
}

static int	int_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] == 32) || (str[i] == '-') || str[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_strjoin(char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen((char *)s2)
			+ 1 + (s1[0] != 0), sizeof(char));
	if (!result)
		ft_clean_exit(s1);
	while (s1[++i])
		result[i] = s1[i];
	if (i != 0)
		result[i++] = ' ';
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (result);
}

int	*entry_check(int argc, char *argv[], int *size)
{
	int		i;
	char	*dest;
	int		*int_dest;

	i = 1;
	if (argc <= 1)
		ft_clean_exit(NULL);
	dest = ft_calloc(sizeof(char), 1);
	while (i < argc)
	{
		dest = ft_strjoin(dest, argv[i]);
		if (!dest)
			ft_clean_exit(NULL);
		i++;
	}
	if (!(*dest))
		ft_clean_exit(dest);
	if (!int_check(dest))
		ft_clean_exit(dest);
	*size = count(dest);
	int_dest = convert_int(dest);
	return (int_dest);
}
