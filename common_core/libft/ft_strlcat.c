/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:46 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/21 17:00:04 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	len;
	size_t	slen;
	size_t	i;

	len = 0;
	i = 0;
	slen = 0;
	while (src[slen])
		slen++;
	while (dst[len])
		len++;
	if (!siz)
		return (slen);
	if (siz <= len)
		return (slen + siz);
	while (len + i < siz - 1 && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (slen + len);
}
