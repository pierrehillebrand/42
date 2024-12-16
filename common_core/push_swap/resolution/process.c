/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:18:47 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/07 13:38:53 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	aux(int *distance, t_list **pile_b, int type)
{
	if (*distance < 0)
	{
		reverse_rotate(pile_b, NULL, type);
		*distance += 1;
	}
	else
	{
		rotate(pile_b, NULL, type);
		*distance -= 1;
	}
}

void	process(t_list **pile_a, t_list **pile_b, int distance, int meilleur)
{
	while ((distance > 0 && meilleur > 0) || (distance < 0 && meilleur < 0))
	{
		if (distance > 0 && meilleur > 0)
		{
			rotate(pile_a, pile_b, 2);
			distance--;
			meilleur--;
		}
		if (distance < 0 && meilleur < 0)
		{
			reverse_rotate(pile_a, pile_b, 2);
			distance++;
			meilleur++;
		}
	}
	while (distance != 0)
		aux(&distance, pile_b, 1);
	while (meilleur != 0)
		aux(&meilleur, pile_a, 0);
	push(pile_b, pile_a, 1);
}
