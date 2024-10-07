/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:29:26 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/20 13:05:29 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		tab = malloc((max - min) * sizeof(int));
		if (tab == NULL)
			return (-1);
		i = 0;
		while (min + i < max)
		{
			tab[i] = min + i;
			i++;
		}
		*range = tab;
		return (i);
	}
}
