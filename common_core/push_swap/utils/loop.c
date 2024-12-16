/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:14:35 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/07 18:18:08 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_add_front(t_list *first, t_list *new)
{
	if (!first)
	{
		new->next = new;
		new->previous = new;
		return ;
	}
	if (first->next == first)
		first->next = new;
	new->next = first;
	new->previous = first->previous;
	first->previous->next = new;
	first->previous = new;
}

void	ft_add_back(t_list *first, t_list *new)
{
	t_list	*current;

	current = first;
	first->previous = new;
	while (current->next && current->next != first)
		current = current->next;
	current->next = new;
	new->previous = current;
	current = current->next;
	current->next = first;
}

void	ft_list_clean(t_list *first)
{
	t_list	*current;
	t_list	*temp;

	if (!first)
		return ;
	current = first;
	while (current->next && current->next != first)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
}

t_list	*create(int *int_dest, int size)
{
	int		i;
	t_list	*new;
	t_list	*first;

	first = malloc(sizeof(t_list));
	first->next = NULL;
	first->previous = NULL;
	first->value = int_dest[0];
	i = 1;
	while (i < size)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_list_clean(first);
			ft_clean_exit(int_dest);
		}
		new->value = int_dest[i];
		ft_add_back(first, new);
		i++;
	}
	return (first);
}
