/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:59:27 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 14:59:16 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_position(t_list *to_place, t_list *top_pile)
{
	t_list	*prev;

	prev = top_pile->previous;
	if (to_place->value < top_pile->value && to_place->value > prev->value)
		return (1);
	else if (to_place->value < top_pile->value && to_place->value < prev->value
		&& prev->value > top_pile->value)
		return (1);
	else if (to_place->value > top_pile->value && to_place->value > prev->value
		&& prev->value > top_pile->value)
		return (1);
	return (0);
}

static void	search(int *util, t_list *pile_a, t_list *pile_b)
{
	int		i;
	int		j;
	t_list	*memory;

	i = 0;
	j = 0;
	memory = pile_a;
	while (!check_position(pile_b, pile_a))
	{
		i++;
		pile_a = pile_a->next;
	}
	pile_a = memory;
	while (!check_position(pile_b, pile_a))
	{
		j--;
		pile_a = pile_a->previous;
	}
	util[0] = i;
	util[1] = j;
}

static void	aux(int *util, t_list *reverse, t_list **pile_b, t_list **pile_a)
{
	int		distance;
	int		i;
	int		temp[2];
	t_list	*current;

	i = 1;
	search(util, *pile_a, *pile_b);
	current = (*pile_b)->next;
	reverse = (*pile_b)->previous;
	distance = 0;
	while (i < max_dist(distance, abs_min(util[0], util[1]))
		&& current != *pile_b)
	{
		search(temp, *pile_a, current);
		test_best(util, temp, &distance, i);
		search(temp, *pile_a, reverse);
		test_best(util, temp, &distance, -i);
		reverse = reverse->previous;
		current = current->next;
		i++;
	}
	process(pile_a, pile_b, distance, abs_min(util[0], util[1]));
}

static void	resolve_a(t_list **pile_a)
{
	t_list	*top;
	t_list	*bottom;
	t_list	*mid;

	top = *pile_a;
	bottom = top->previous;
	mid = top->next;
	if (top->value > mid->value && top->value > bottom->value
		&& mid->value < bottom->value)
		rotate(pile_a, NULL, 0);
	else if (top->value < mid->value && top->value > bottom->value)
		reverse_rotate(pile_a, NULL, 0);
	else if (top->value > mid->value && top->value < bottom->value)
		switch_list(pile_a, NULL, 0);
	else if (top->value < mid->value && top->value < bottom->value
		&& mid->value > bottom->value)
	{
		reverse_rotate(pile_a, NULL, 0);
		switch_list(pile_a, NULL, 0);
	}
	else if (top->value > mid->value && top->value > bottom->value)
	{
		rotate(pile_a, NULL, 0);
		switch_list(pile_a, NULL, 0);
	}
}

void	start(int size, t_list **pile_a, t_list **pile_b)
{
	int		size_a;
	int		size_b;
	int		util[3];
	t_list	reverse;

	size_a = size;
	size_b = 0;
	if (size == 2)
	{
		switch_list(pile_a, NULL, 0);
		return ;
	}
	while (size_a > 3)
	{
		push(pile_a, pile_b, 0);
		size_a--;
		size_b++;
	}
	resolve_a(pile_a);
	while (size_b-- > 0)
		aux(util, &reverse, pile_b, pile_a);
	rotate_finish(pile_a);
}
/*
int     main(void)
{
        int     int_dest[] = {1, -3, 4, 5};
        int     int_b[] = {-2, -1, 0, 2, 3};
        t_list  *first;
        t_list  *top_b;

        first = create(int_dest, 4);
        top_b = create(int_b, 5);
	reverse_rotate(&first, &top_b, 2);
	printf("first : %d\ttop_b : %d\n", first->value, top_b->value);
}
*/
