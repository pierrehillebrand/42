/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:27:23 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/18 21:35:55 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		test_format(char *str, int *conditions);
//verifie que la chaine de charactere recue 
//est composees de 16 chiffre compris entre 1 et 4

int		resolution(int tableau[16], int *conditions);

int		test_conditions(int *conditions);

void	print_res(int tableau[16]);

int	main(int argc, char *argv[])
{
	int	tableau[16];
	int	conditions[16];

	if (argc != 2)
		write(1, "Error\n", 6);
	else if (!test_format(argv[1], conditions) || !test_conditions(conditions))
		write(1, "Error\n", 6);
	else
	{
		if (resolution(tableau, conditions) == 0)
		{
			write(1, "Error\n", 6);
		}
		else
		{
			print_res(tableau);
		}
	}
	return (0);
}

int	test_format(char *str, int *conditions)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 1)
		{
			if (str[i] != 32)
				return (0);
		}
		else if (!(str[i] >= '1' && str[i] <= '4'))
			return (0);
		else
			conditions[i / 2] = str[i] - 48;
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	test_conditions(int *conditions)
{
	int	i;
	int	j;
	int	a;

	i = 8;
	j = 1;
	while (j <= 3)
	{
		while (i < 12 / j)
		{
			a = conditions[i] + conditions[i + 4];
			if (a <= 2 || a > 5)
				return (0);
			i++;
		}
		i = 0;
		j += 2;
	}
	return (1);
}

void	print_res(int tableau[16])
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a = '0' + tableau[i * 4 + j];
			write(1, &a, 1);
			j++;
			if (j == 4)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
		}
		i++;
	}
}
