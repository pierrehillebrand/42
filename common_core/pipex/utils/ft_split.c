/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:44:30 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/01 13:56:21 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	word_count(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != 0 && str[i] == sep)
			i++;
		if (str[i] != 0 && str[i] != sep)
			count++;
		while (str[i] != 0 && str[i] != sep)
			i++;
	}
	return (count);
}

static char	*ft_dup(char const *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}	

static char	*deal(char **tab, int words, const char *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] != 0 && s[i] != c)
		{
			tab[words] = ft_dup(s + i, c);
			if (!tab[words])
			{
				while (tab[j])
					free(tab[j++]);
				free(tab);
				return (NULL);
			}
			words++;
		}
		while (s[i] != 0 && s[i] != c)
			i++;
	}
	return (tab[0]);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[0] = "a";
	tab[words] = NULL;
	words = 0;
	if (tab[0])
		if (!deal(tab, words, s, c))
			return (NULL);
	return (tab);
}
