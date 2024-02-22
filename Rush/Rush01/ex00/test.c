/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:08:51 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/18 16:29:08 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	initialisation(int *grille, int *conditions);

void	initialisation_2(int *grille, int *conditions);

void	depart(int *grille, int indice, int chiffre, int i);

void	placement(int *grille, int indice, int chiffre, int type);

void	init(int *grille);

void	initialisation(int *grille, int *conditions)
{
	int	i;

	init(grille);
	i = 0;
	while (i < 4)
	{
		if (conditions[i] == 1)
			depart(grille, i, 1, 0);
		if (conditions[i + 4] == 1)
			depart(grille, i, -1, 0);
		if (conditions[i] == 4)
			depart(grille, i, 4, 0);
		if (conditions[i + 4] == 4)
			depart(grille, i, -4, 0);
		if (conditions[i] == 3 && conditions[i + 4] == 2)
			depart(grille, i, 5, 0);
		if (conditions[i] == 2 && conditions[i + 4] == 3)
			depart(grille, i, -5, 0);
		if (conditions[i] == 1 && conditions[i + 4] == 2)
			depart(grille, i, 3, 0);
		if (conditions[i] == 2 && conditions[i + 4] == 1)
			depart(grille, i, -3, 0);
		i++;
	}
	initialisation_2(grille, conditions);
}

void	initialisation_2(int *grille, int *conditions)
{
	int	i;

	i = 8;
	while (i < 12)
	{
		if (conditions[i] == 1)
			depart(grille, i, 1, 0);
		if (conditions[i + 4] == 1)
			depart(grille, i, -1, 0);
		if (conditions[i] == 4)
			depart(grille, i, 4, 0);
		if (conditions[i + 4] == 4)
			depart(grille, i, -4, 0);
		if (conditions[i] == 3 && conditions[i + 4] == 2)
			depart(grille, i, 5, 0);
		if (conditions[i] == 2 && conditions[i + 4] == 3)
			depart(grille, i, -5, 0);
		if (conditions[i] == 1 && conditions[i + 4] == 2)
			depart(grille, i, 3, 0);
		if (conditions[i] == 2 && conditions[i + 4] == 1)
			depart(grille, i, -3, 0);
		i++;
	}
}

void	init(int *grille)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		grille[i] = 0;
		i++;
	}
}

void	depart(int *grille, int indice, int chiffre, int i)
{
	int	depart;
	int	signe;
	int	add;

	i = 0;
	signe = 1;
	if (chiffre < 0)
		signe = -1;
	if (indice < 8)
	{
		add = 4 * signe;
		if (chiffre > 0)
			depart = indice;
		else
			depart = 15 - (3 - indice);
	}	
	else
	{
		add = signe;
		if (chiffre > 0)
			depart = (indice % 8) * 4;
		else
			depart = (16 - 4 * (3 - indice % 8)) - 1;
	}
	placement(grille, chiffre, depart, add);
}

void	placement(int *grille, int chiffre, int depart, int add)
{
	int	i;

	i = 0;
	if (chiffre == 1 || chiffre == -1)
		grille[depart] = 4;
	if (chiffre == 4 || chiffre == -4)
	{
		while (i < 4)
		{
			grille[depart + add * i] = i + 1;
			i++;
		}
	}
	if (chiffre == 5 || chiffre == -5)
		grille[depart + 2 * add] = 4;
	if (chiffre == 3 || chiffre == -3)
		grille[depart + 3 * add] = 3;
}
