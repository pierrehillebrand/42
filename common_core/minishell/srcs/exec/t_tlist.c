/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:38:15 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/05 15:00:39 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_tlist	*t_tlist_create(t_list *tokens)
{
	t_tlist	*new;
	t_tlist	*first;
	t_tlist	*temp;

	first = (t_tlist *)tokens;
	tokens = tokens->next;
	temp = first;
	while (tokens)
	{
		new = (t_tlist *)tokens;
		temp->next = new;
		temp = new;
		tokens = tokens->next;
	}
	return (first);
}
