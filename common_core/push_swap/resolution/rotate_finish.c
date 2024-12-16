/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:18:47 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:03:45 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	aux(t_list **pile_a, int i, int j)
{
	if (i < -j)
	{
		while (i > 0)
		{
			rotate(pile_a, NULL, 0);
			i--;
		}
		return ;
	}
	while (j < 0)
	{
		reverse_rotate(pile_a, NULL, 0);
		j++;
	}
}

void	rotate_finish(t_list **pile_a)
{
	int		i;
	int		j;
	t_list	*test;

	i = 0;
	j = 0;
	test = (*pile_a);
	while (!(test->value < test->next->value
			&& test->value < test->previous->value))
	{
		test = test->next;
		i++;
	}
	test = *pile_a;
	while (!(test->value < test->next->value
			&& test->value < test->previous->value))
	{
		test = test->previous;
		j--;
	}
	aux(pile_a, i, j);
}
