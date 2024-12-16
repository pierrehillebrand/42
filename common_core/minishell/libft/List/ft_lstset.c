/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:24:17 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/02 19:10:11 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstset(t_list *lst, int index, void *content)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
		{
			lst->content = content;
			return ;
		}
		lst = lst->next;
		i++;
	}
}
