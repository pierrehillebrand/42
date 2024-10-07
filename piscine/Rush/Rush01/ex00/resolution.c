/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:20:36 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/18 21:40:52 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	initialisation(int *grille, int *conditions);

int		check_rowcol(int *grille, int x, int nbr);

int		solve_row_2(int *grille, int *x);

void	refresh(int *grille, int *temp);

int	solve_row(int *grille, int *x)
{
	int	res;

	while (x[0] != x[2])
	{
		res = x[1];
		if (grille[x[0]] == 0)
		{
			solve_row_2(grille, x);
		}
		else
			x[0] += 1;
	}
	return (1);
}

int	solve_row_2(int *grille, int *x)
{
	int	test;
	int	res;

	res = x[1];
	test = 0;
	while (res > 0)
	{
		if (check_rowcol(grille, x[0], res) == 0 && grille[x[0]] == 0)
		{
			grille[x[0]] = res;
			x[1] = 4;
			test = 1;
		}
		res--;
	}
	if (test == 0)
		return (0);
	return (1);
}

void	refresh(int *grille, int *temp)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		temp[i] = grille[i];
		i++;
	}
}

int	mini(int *grille, int *temp, int *x)
{
	int	truc;

	truc = 4;
	while (x[1] > 0 && truc > 0)
	{
		if (solve_row(grille, x) == 0)
		{
			x[0] = (x[0] / 4) * 4;
			refresh(temp, grille);
			x[1]--;
			truc--;
		}
		else
		{
			x[1] = 0;
			refresh(grille, temp);
		}
	}
	if (truc == 0)
		return (0);
	x[1] = 4;
	truc = 4;
	return (1);
}

int	resolution(int *grille, int *conditions)
{
	int	temp[16];
	int	x[3];
	int	i;
	int	a;

	initialisation(temp, conditions);
	initialisation(grille, conditions);
	x[0] = 0;
	x[1] = 4;
	i = 1;
	while (i < 5)
	{
		x[2] = 4 * i;
		a = mini(grille, temp, x);
		i++;
		if (a == 0)
			i = 5;
	}
	if (a == 0)
		return (0);
	return (1);
}
