/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:24:04 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/16 15:28:52 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	temp = (char *)(s);
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
	s = (void *)(s);
	return (s);
}
