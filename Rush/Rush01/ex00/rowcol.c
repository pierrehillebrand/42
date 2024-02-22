/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rowcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:57:07 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/18 21:02:59 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rowcol(int *grille, int x, int nbr)
{
	int	test;
	int	i;

	test = 0;
	i = 0;
	while (i < 4)
	{
		if (grille[x / 4 * 4 + i] == nbr)
			test = 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grille[i * 4 + x % 4] == nbr)
			test = 1;
		i++;
	}
	return (test);
}
