/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:18:58 by phillebr          #+#    #+#             */
/*   Updated: 2024/05/21 16:54:49 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	c = c % 256;
	i = 0;
	while (s[i])
		i++;
	if (s[i] == c)
		return ((char *) s + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", strrchr("iesgihelisngilj", 'j'));
}
*/
