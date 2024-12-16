/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:18:11 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 16:59:31 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_iterator.h"

void	array_it_init(t_array_iterator *it, void *array, size_t size)
{
	it->array = array;
	it->size = size;
	it->index = 0;
	it->curent = array;
}

void	array_it_next(t_array_iterator *it)
{
	it->index++;
	it->curent += it->size;
}

void	*array_it_get(t_array_iterator *it)
{
	return (it->curent);
}

void	*array_it_get_and_next(t_array_iterator *it)
{
	void	*ret;

	ret = it->curent;
	array_it_next(it);
	return (ret);
}
