/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iterator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:18:08 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 16:59:18 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_ITERATOR_H
# define ARRAY_ITERATOR_H

# include <stddef.h>

typedef struct s_array_iterator
{
	void	*array;
	size_t	size;
	size_t	index;
	void	*curent;
}	t_array_iterator;

void	array_it_init(t_array_iterator *it, void *array, size_t size);
void	array_it_next(t_array_iterator *it);
void	*array_it_get(t_array_iterator *it);
void	*array_it_get_and_next(t_array_iterator *it);

#endif