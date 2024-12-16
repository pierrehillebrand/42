/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:59:36 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/03 10:59:38 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images_b(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit[1])
		mlx_destroy_image(game->mlx, game->exit[1]);
	if (game->exit[0])
		mlx_destroy_image(game->mlx, game->exit[0]);
	if (game->player[0])
		mlx_destroy_image(game->mlx, game->player[0]);
	if (game->player[1])
		mlx_destroy_image(game->mlx, game->player[1]);
	if (game->player[2])
		mlx_destroy_image(game->mlx, game->player[2]);
	if (game->player[3])
		mlx_destroy_image(game->mlx, game->player[3]);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
}

int	cleanup_b(t_game *game)
{
	if (game->map)
		clean_map(game->map, game->height);
	if (game)
	{
		if (game->character)
			free(game->character);
		destroy_images_b(game);
		if (game->mlx && game->window)
		{
			mlx_clear_window(game->mlx, game->window);
			mlx_destroy_window(game->mlx, game->window);
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
		game = NULL;
	}
	return (0);
}

void	destroy_images(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit[1])
		mlx_destroy_image(game->mlx, game->exit[1]);
	if (game->exit[0])
		mlx_destroy_image(game->mlx, game->exit[0]);
	if (game->player[0])
		mlx_destroy_image(game->mlx, game->player[0]);
	if (game->player[1])
		mlx_destroy_image(game->mlx, game->player[1]);
	if (game->player[2])
		mlx_destroy_image(game->mlx, game->player[2]);
	if (game->player[3])
		mlx_destroy_image(game->mlx, game->player[3]);
}

int	cleanup(t_game *game)
{
	if (game->map)
		clean_map(game->map, game->height);
	if (game)
	{
		destroy_images(game);
		if (game->mlx && game->window)
		{
			mlx_clear_window(game->mlx, game->window);
			mlx_destroy_window(game->mlx, game->window);
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
		game = NULL;
	}
	return (0);
}
