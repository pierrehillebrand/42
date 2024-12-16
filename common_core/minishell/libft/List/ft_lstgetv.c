/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:07 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/02 19:09:55 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_lstgetv(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst->content);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
