/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:16:16 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/15 11:47:39 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	array = malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (array);
	i = 0;
	while (min + i < max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
