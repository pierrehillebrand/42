/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:47:57 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/14 17:42:05 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	sstrcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*ordre;

	i = 1;
	while (i < argc)
	{
		while (i > 1 && sstrcmp(argv[i], argv[i - 1]) < 0)
		{
			ordre = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = ordre;
			i--;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		putstr(argv[i]);
		i++;
	}
	return (0);
}
