/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:47:10 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/02 11:14:23 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **top_a, t_list **top_b, int type)
{
	t_list		*temp_a;
	t_list		*temp_b;
	t_list		*memory;
	const char	*list[] = {"pb", "pa", NULL};

	if (top_a && *top_a)
	{
		temp_b = NULL;
		ft_putstr((char *)list[type]);
		memory = (*top_a);
		if ((*top_a) && (*top_a)->next != *top_a)
		{
			temp_a = (*top_a)->previous;
			temp_b = (*top_a)->next;
			temp_a->next = temp_b;
			temp_b->previous = temp_a;
			(*top_a) = temp_b;
		}
		else
			(*top_a) = NULL;
		ft_add_front(*top_b, memory);
		(*top_b) = memory;
	}
}

void	rotate(t_list **top, t_list **top_optionnel, int type)
{
	const char	*list[] = {"ra", "rb", "rr", NULL, NULL};

	ft_putstr((char *)list[type]);
	if (top_optionnel && *top_optionnel)
	{
		if (type == 2 || type == 4)
			(*top_optionnel) = (*top_optionnel)->next;
	}
	if (top && *top)
		*top = (*top)->next;
}

void	reverse_rotate(t_list **top, t_list **top_optionnel, int type)
{
	const char	*list[] = {"rra", "rrb", "rrr", NULL, NULL};

	ft_putstr((char *)list[type]);
	if (top_optionnel && *top_optionnel)
	{
		if (type == 2 || type == 4)
			(*top_optionnel) = (*top_optionnel)->previous;
	}
	if (top && *top)
		*top = (*top)->previous;
}

static void	lswap(t_list **top)
{
	t_list	*temp;

	if (!top || !*top)
		return ;
	temp = (*top)->next;
	temp->next->previous = *top;
	temp->previous = (*top)->previous;
	(*top)->next = temp->next;
	(*top)->previous->next = temp;
	(*top)->previous = temp;
	temp->next = (*top);
	*top = temp;
}

void	switch_list(t_list **top, t_list **top_optionnel, int type)
{
	t_list		*temp;
	t_list		*temp_opt;
	const char	*list[] = {"sa", "sb", "ss", NULL, NULL};

	ft_putstr((char *)list[type]);
	if (top && *top)
	{
		temp = (*top)->next;
		if (temp->next != (*top))
			lswap(top);
		else
			(*top) = (*top)->next;
	}
	if ((type == 2 || type == 4) && top_optionnel && *top_optionnel)
	{
		temp_opt = (*top_optionnel)->next;
		if (temp_opt->next != (*top_optionnel))
			lswap(top_optionnel);
		else
			*top_optionnel = (*top_optionnel)->next;
	}
}
