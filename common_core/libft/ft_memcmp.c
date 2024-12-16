/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:35:13 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/21 16:33:58 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_1;
	unsigned char	*temp_2;

	temp_1 = (unsigned char *)s1;
	temp_2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*(temp_1 + i) == *(temp_2 + i) && i < n - 1)
		i++;
	return (temp_1[i] - temp_2[i]);
}
