/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:10:22 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/14 10:54:01 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ligne(char debut, char fin, char mid, int width)
{
	int	i;

	i = 0;
	if (width > 0)
		write(1, &debut, 1);
	while (i < width - 2)
	{
		write(1, &mid, 1);
		i++;
	}
	if (width > 1)
		write(1, &fin, 1);
	write(1, "\n", 1);
}

void	rush(int width, int height)
{
	int	i;

	i = 0;
	if (height < 0)
		return ;
	if (height <= 2)
	{
		while (i < height)
		{
			ligne('A', 'C', 'B', width);
			i++;
		}
	}
	else
	{
		ligne('A', 'C', 'B', width);
		while (i < width - 2)
		{
			ligne('B', 'B', ' ', width);
			i++;
		}
		ligne('A', 'C', 'B', width);
	}
}

int	main(void)
{
	rush(40,-4);
	return (0);
}
