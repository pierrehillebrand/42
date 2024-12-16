/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:23:45 by lfarhi            #+#    #+#             */
/*   Updated: 2024/10/09 13:24:01 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
