/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:39 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/08 17:02:17 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
		}
		else if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}
