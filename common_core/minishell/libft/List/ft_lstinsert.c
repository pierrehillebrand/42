/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:10 by lfarhi            #+#    #+#             */
/*   Updated: 2024/11/28 16:59:35 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_lstinsert_init(t_list **lst, int index, t_list *sub_lst)
{
	if (!lst || !sub_lst)
		return (1);
	if (!*lst)
	{
		*lst = sub_lst;
		return (1);
	}
	if (index == 0)
	{
		ft_lstlast(sub_lst)->next = *lst;
		*lst = sub_lst;
		return (1);
	}
	return (0);
}

void	ft_lstinsert(t_list **lst, int index, t_list *sub_lst)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	if (ft_lstinsert_init(lst, index, sub_lst))
		return ;
	tmp = *lst;
	prev = NULL;
	i = 0;
	while (tmp && i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (prev)
		prev->next = sub_lst;
	while (sub_lst->next)
		sub_lst = sub_lst->next;
	sub_lst->next = tmp;
}
