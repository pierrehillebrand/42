/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:13:54 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/26 19:39:29 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_char(char x)
{
	write(1, &x, 1);
}

void	putnbr(long x)
{
	int		y;
	char	c;

	y = 1;
	while (y <= x)
		y *= 10;
	y /= 10;
	while (y > 0)
	{
		c = (x / y) + '0';
		put_char(c);
		x = x - ((x / y) * y);
		y = y / 10;
	}
	putchar('\n');
}

char	*ft_itoa(int n, t_game *game)
{
	unsigned int	count;
	unsigned int	nbr;
	unsigned int	i;

	if (game->character)
		free(game->character);
	i = 0;
	count = 1;
	nbr = n;
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	game->character = ft_calloc(sizeof(char), (count + 1));
	if (!game->character)
		return (NULL);
	while (i < count)
	{
		game->character[count - 1 - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (game->character);
}
