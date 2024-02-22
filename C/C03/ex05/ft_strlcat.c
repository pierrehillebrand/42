/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:38:37 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/12 17:26:35 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				test;

	i = 0;
	j = 0;
	test = 1;
	while (dest[i] != '\0')
		i++;
	if (size <= i)
		test = 0;
	while (src[j] != '\0')
	{
		if (j < size - i - 1 && test)
			dest[i + j] = src[j];
		if (j == size - i - 1 && test)
			dest[i + j] = '\0';
		j++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	if (size < i)
		return (j + size);
	else
		return (i + j);
}
