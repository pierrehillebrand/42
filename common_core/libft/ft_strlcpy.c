/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:46:28 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/21 16:35:24 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
		i++;
	if (siz == 0)
		return (i);
	j = 0;
	while (src[j] && j < siz - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = 0;
	return (i);
}
