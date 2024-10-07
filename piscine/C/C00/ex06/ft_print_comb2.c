/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:00:42 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/07 19:36:59 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_string_n(int a, int b)
{
	char	x;

	x = a / 10 + '0';
	write(1, &x, 1);
	x = a % 10 + '0';
	write(1, &x, 1);
	write(1, " ", 1);
	x = b / 10 + '0';
	write(1, &x, 1);
	x = b % 10 + '0';
	write(1, &x, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	put_string_end(int a, int b)
{
	char	x;

	x = a / 10 + '0';
	write(1, &x, 1);
	x = a % 10 + '0';
	write(1, &x, 1);
	write(1, " ", 1);
	x = b / 10 + '0';
	write(1, &x, 1);
	x = b % 10 + '0';
	write(1, &x, 1);
}

void	put_string(int a, int b)
{
	if (a + b == 197)
	{
		put_string_end(a, b);
	}
	else
	{
		put_string_n(a, b);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			put_string(a, b);
			b++;
		}
		a++;
	}
}
