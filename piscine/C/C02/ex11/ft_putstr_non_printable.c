/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:54:19 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/11 12:14:10 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	def(unsigned int  a)
{
	int 		i;
	char	c;
	char	hexa[17];

	i = 0;
	while (i < 17)
	{
		if (i < 10)
			hexa[i] = '0' + i;
		else
			hexa[i] = 'a' + i - 10;
		i++;
	}
	c = hexa[a];
	return (c);
}

void	conversion(unsigned int  a)
{
	char	b;

	b = def(a / 16);
	write(1, &b, 1);
	b = def(a % 16);
	write(1, &b, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			conversion(str[i]);
		}
		else
		{
			write(1, str + i, 1);
		}
		i++;
	}
}
