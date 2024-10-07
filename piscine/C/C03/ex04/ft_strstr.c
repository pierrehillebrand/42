/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:46:01 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/12 17:13:04 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find(char *str, char *to_find)
{
	int	j;
	int	test;

	j = 1;
	test = 1;
	while (to_find[j] != '\0')
	{
		if (to_find[j] != str[j])
			test = 0;
		j++;
	}
	return (test);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	test;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == *to_find)
		{
			test = find(str + i, to_find);
			if (test == 1)
				return (str + i);
		}
		i++;
	}
	return (0);
}
