/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:42:06 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/20 18:58:40 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in(char *charset, char test)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == test)
			return (1);
		i++;
	}
	return (0);
}

void	dup(char *str, char **list, char *charset, int indice)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (str[i] != '\0' && is_in(charset, str[i]) == 0)
		i++;
	string = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		string[j] = str[j];
		j++;
	}
	string[j] = '\0';
	list[indice] = string;
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (is_in(charset, str[i]))
			i++;
		if (str[i] != '\0' && is_in(charset, str[i]) == 0)
			count++;
		while (str[i] != '\0' && is_in(charset, str[i]) == 0)
			i++;
	}
	if (i != 0 && is_in(charset, str[i - 1]) == 0)
		count++;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**list;
	int		i;
	int		j;

	j = 0;
	i = 0;
	size = count_words(str, charset) + 1;
	list = malloc(sizeof(char *) * size);
	if (!list)
		return (0);
	list[size - 1] = 0;
	while (str[i] != '\0')
	{
		while (is_in(charset, str[i]))
			i++;
		if (str[i] != '\0' && is_in(charset, str[i]) == 0)
		{
			dup(str + i, list, charset, j);
			j++;
		}
		while (str[i] != '\0' && is_in(charset, str[i]) == 0)
			i++;
	}
	return (list);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	**list;
	argc++;
	int	i = 0;

	list = ft_split(argv[1], argv[2]);
	while (list[i] != 0)
	{
		printf("%s\n", list[i]);
		free(list[i]);
		i++;
	}
	free(list);
}*/
