/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:17:42 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/03 16:28:51 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_next(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
	game->wall, 32 * j, 32 * i);
	if (game->map[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->window, \
	game->enemy, 32 * j, 32 * i);
}

void	put_map_b(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->floor, 32 * j, 32 * i);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->exit[game->is_open], 32 * j, 32 * i);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->player[1], 32 * j, 32 * i);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->collect, 32 * j, 32 * i);
			put_next(game, i, j);
		}
	}
}

void	put_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->floor, 32 * j, 32 * i);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->exit[game->is_open], 32 * j, 32 * i);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->player[1], 32 * j, 32 * i);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->collect, 32 * j, 32 * i);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
			game->wall, 32 * j, 32 * i);
		}
	}
}
