/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:17:19 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 16:59:50 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_H
# define LIST_ITERATOR_H

# include <stddef.h>

typedef struct s_list	t_list;

typedef struct s_list_iterator
{
	t_list	*list;
	t_list	*current;
	size_t	index;
}						t_list_iterator;

void	list_it_init(t_list_iterator *it, t_list *list);
void	list_it_next(t_list_iterator *it);
t_list	*list_it_get(t_list_iterator *it);
int		list_it_end(t_list_iterator *it);
t_list	*list_it_get_and_next(t_list_iterator *it);

#endif