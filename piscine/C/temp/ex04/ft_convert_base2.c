/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:27:44 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/19 19:34:42 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base(char test, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (test == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	transformation(char *str, char *base, int taille)
{
	int	y;
	int	i;
	int	z;

	y = 0;
	i = 0;
	z = is_base(str[i], base);
	while (z != -1 && str[i])
	{
		y = y * taille + z;
		i++;
		z = is_base(str[i], base);
	}
	return (y);
}

int	ft_atoi_base(char *str, char *base, int taille)
{
	int	i;
	int	signe;
	int	x;
	int	test;

	x = 0;
	test = 1;
	i = 0;
	signe = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	x = transformation(str + i, base, taille);
	return (signe * x);
}
