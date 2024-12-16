/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:02:20 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:08:35 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	abs_min(int a, int b)
{
	if (abs(a) > abs(b))
		return (b);
	return (a);
}

int	max_dist(int distance, int nbr_rotations)
{
	if (distance > 0 && nbr_rotations > 0)
	{
		if (distance > nbr_rotations)
			return (distance);
		return (nbr_rotations);
	}
	else if (distance < 0 && nbr_rotations < 0)
	{
		if (abs(distance) > abs(nbr_rotations))
			return (abs(distance));
		return (abs(nbr_rotations));
	}
	return (abs(distance) + abs(nbr_rotations));
}

void	test_best(int *util, int *temp, int *distance, int i)
{
	int	tot_prev;
	int	best_tmp;

	tot_prev = abs_min(max_dist(*distance, util[0]),
			max_dist(*distance, util[1]));
	if (max_dist(i, temp[0]) > max_dist(i, temp[1]))
		best_tmp = temp[1];
	else
		best_tmp = temp[0];
	if (tot_prev > abs(max_dist(i, best_tmp)))
	{
		*distance = i;
		util[0] = best_tmp;
		util[1] = best_tmp;
	}
}
