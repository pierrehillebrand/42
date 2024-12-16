/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:15:49 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/23 15:32:53 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	temp = (*lst);
	while (*(lst) != NULL)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free((*lst));
		(*lst) = temp;
	}
}
