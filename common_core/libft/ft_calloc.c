/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:57:01 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/23 11:01:47 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	char	*temp;
	size_t	i;

	if (nmemb != 0 && size != 0)
	{
		if (nmemb > INT_MAX || size > INT_MAX || nmemb * size > INT_MAX)
			return (NULL);
	}
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	temp = (char *)(dest);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	dest = (void *)(temp);
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	void	*dest = calloc(0, 1);
	free(dest);
}
*/
