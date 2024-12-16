/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:49:06 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/04 15:03:20 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_lstindex(t_list *lst, t_list *node)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		if (lst == node)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
