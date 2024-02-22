/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:50:17 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/14 13:08:57 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (-1);
		else
		{
			j = 1;
			while (base[i + j] != '\0')
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

void	rec(unsigned int nb, int taille, char *base)
{
	int	x;

	if (nb != 0)
	{
		x = nb % taille;
		rec(nb / taille, taille, base);
		write(1, base + x, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = verif_base(base);
	if (i > 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			rec(-nbr, i, base);
		}
		else if (nbr == 0)
			write(1, base, 1);
		else
			rec(nbr, i, base);
	}
}
