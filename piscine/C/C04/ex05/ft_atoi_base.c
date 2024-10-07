/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:51:11 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/13 16:21:52 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (-1);
		else
		{
			j = 1;
			while (base[i + j] != '\0')
			{
				if (base [i] == base[i + j])
					return (-4);
				j++;
			}
		}
		i++;
	}
	if (i < 2)
		return (-2);
	return (i);
}

int	is_base(char test, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
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
	while (z != -1 && str[i] != '\0')
	{
		y = y * taille + z;
		i++;
		z = is_base(str[i], base);
	}
	return (y);
}

int	ft_atoi_base(char *str, char *base)
{
	int			taille;
	int			i;
	int			test;
	long int	x;

	x = 0;
	test = 1;
	taille = check_base(base);
	if (taille > 0)
	{
		i = 0;
		while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				test = -test;
			i++;
		}
		x = transformation(str + i, base, taille);
	}
	return (test * x);
}
