/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:47:21 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/12 13:34:59 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
		i++;
	while (src[k] != '\0')
	{
		dest[k] = src[k];
		i++;
	}
	dest[k] = '\0';
	return (i);
}
