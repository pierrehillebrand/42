/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:17:31 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 16:59:58 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_iterator.h"
#include "../../libft.h"

void	list_it_init(t_list_iterator *it, t_list *list)
{
	it->list = list;
	it->current = list;
	it->index = 0;
}

void	list_it_next(t_list_iterator *it)
{
	if (it->current == NULL)
		return ;
	it->current = it->current->next;
	it->index++;
}

t_list	*list_it_get(t_list_iterator *it)
{
	return (it->current);
}

int	list_it_end(t_list_iterator *it)
{
	return (it->current == NULL);
}

t_list	*list_it_get_and_next(t_list_iterator *it)
{
	t_list	*ret;

	ret = it->current;
	list_it_next(it);
	return (ret);
}
