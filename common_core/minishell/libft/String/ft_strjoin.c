/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:27:47 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 18:39:11 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	char	*res;

	len1 = ft_strlen(s1);
	res = (char *)malloc(len1 + ft_strlen(s2) + 1);
	res[0] = '\0';
	if (!res)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(res, s1, -1);
	if (s2 != NULL)
		ft_strlcpy(res + len1, s2, -1);
	return (res);
}
