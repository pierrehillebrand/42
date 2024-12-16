/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:36:17 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/01 14:45:30 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2, char separateur)
{
	char	*str;
	int		i;
	int		j;

	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2)
			+ (separateur != '\0') + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	if (separateur != '\0')
		str[i] = separateur;
	i++;
	while (s2[++j])
		str[i + j] = s2[j];
	return (str);
}
