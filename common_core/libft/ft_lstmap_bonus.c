/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:12 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/16 12:05:58 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*test;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst != NULL)
	{
		temp = (*f)(lst->content);
		test = ft_lstnew(temp);
		if (!test)
		{
			free(temp);
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first, test);
		lst = lst->next;
	}
	return (first);
}
