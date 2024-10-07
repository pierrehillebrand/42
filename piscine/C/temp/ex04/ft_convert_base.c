/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:26:49 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/20 19:09:40 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char *temp_str, int i);

int		ft_atoi_base(char *str, char *base, int taille);

int		preparations(char *nbr, char *base_from, char *base_to, char *temp_str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (-1);
		else
		{
			j = 1;
			while (base[i + j])
			{
				if (base[i] == base[i + j])
					return (-1);
				j++;
			}
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	temp_str[40];
	int		size;
	int		i;
	char	*final;

	size = preparations(nbr, base_from, base_to, temp_str);
	if (size == 0)
		return (0);
	i = 0;
	final = malloc(sizeof(char) * size);
	if (temp_str[0] == '-')
	{
		i++;
		final[0] = '-';
	}
	while (i < size)
	{
		if (temp_str[0] == '-')
			final[size - i] = temp_str[i];
		else
			final[size - i - 1] = temp_str[i];
		i++;
	}
	return (final);
}

int	preparations(char *nbr, char *base_from, char *base_to, char *temp_str)
{
	int	base_from_len;
	int	base_to_len;
	int	temp;
	int	i;
	int	size;

	i = 0;
	while (i < 40)
	{
		temp_str[i] = '\0';
		i++;
	}
	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	if (base_from_len < 2 || base_to_len < 2)
		return (0);
	temp = ft_atoi_base(nbr, base_from, base_from_len);
	ft_putnbr_base(temp, base_to, temp_str, 0);
	size = ft_strlen(temp_str);
	return (size);
}

void	ft_putnbr_base(int nbr, char *base, char *temp_str, int i)
{
	int	taille;

	taille = ft_strlen(base);
	if (nbr < 0)
	{
		temp_str[0] = '-';
		i++;
		ft_putnbr_base(-nbr, base, temp_str, i);
	}
	else if (nbr < taille)
	{
		temp_str[i] = base[nbr];
	}
	else
	{
		ft_putnbr_base(nbr % taille, base, temp_str, i);
		ft_putnbr_base(nbr / taille, base, temp_str, i + 1);
	}
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	argc++;
	char *test = ft_convert_base(argv[1], argv[2], argv[3]);

	printf("test : %s",test);
	free(test);
}*/
