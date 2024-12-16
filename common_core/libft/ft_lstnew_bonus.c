/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:55:05 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/20 14:39:56 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*start;

	start = malloc(sizeof(t_list));
	if (!start)
		return (NULL);
	start->next = NULL;
	start->content = content;
	return (start);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *truc = ft_lstnew("aha");
	printf("%p\n", truc->content);
	free(truc);
}
*/
