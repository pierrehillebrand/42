/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:33:17 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/08 10:35:45 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(int n, char x, char c);

void	ft_print_combn(int n)
{
	char	x;

	n--;
	x = '0' + n;
	rec(n, x, '0');
}

void	rec(int n, char x, char c)
{
	while (c <= '9' - n)
	{
		write(1, &c, 1);
		if (x > '0')
		{
			rec(n--, x--, c + 1);
		}
		else
		{
			write(1, "\n", 1);
		}
	c++;
	}
}

void	main(void)
{
	ft_print_combn(1);
}
