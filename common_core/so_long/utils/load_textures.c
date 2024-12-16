/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:41:59 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/03 14:42:00 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	next_b(t_game *game, int *s)
{
	game->player[3] = mlx_xpm_file_to_image(game->mlx, PLAYER_U, s, s);
	if (!game->player[3])
		clean_exit_b(game, "Problem loading textures\n");
	game->enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, s, s);
	if (!game->player[3])
		clean_exit_b(game, "Problem loading textures\n");
}

void	load_textures_b(t_game *game, int *s)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, s, s);
	if (!game->wall)
		clean_exit_b(game, "Problem loading textures\n");
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, CLOSED, s, s);
	if (!game->exit[0])
		clean_exit_b(game, "Problem loading textures\n");
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, OPEN, s, s);
	if (!game->exit[1])
		clean_exit_b(game, "Problem loading textures\n");
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, s, s);
	if (!game->collect)
		clean_exit_b(game, "Problem loading textures\n");
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, s, s);
	if (!game->floor)
		clean_exit_b(game, "Problem loading textures\n");
	game->player[0] = mlx_xpm_file_to_image(game->mlx, PLAYER_R, s, s);
	if (!game->player[0])
		clean_exit_b(game, "Problem loading textures\n");
	game->player[1] = mlx_xpm_file_to_image(game->mlx, PLAYER_D, s, s);
	if (!game->player[1])
		clean_exit_b(game, "Problem loading textures\n");
	game->player[2] = mlx_xpm_file_to_image(game->mlx, PLAYER_L, s, s);
	if (!game->player[2])
		clean_exit_b(game, "Problem loading textures\n");
	next_b(game, s);
}

static void	next(t_game *game, int *s)
{
	game->player[3] = mlx_xpm_file_to_image(game->mlx, PLAYER_U, s, s);
	if (!game->player[3])
		clean_exit(game, "Problem loading textures\n");
}

void	load_textures(t_game *game, int *s)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, s, s);
	if (!game->wall)
		clean_exit(game, "Problem loading textures\n");
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, CLOSED, s, s);
	if (!game->exit[0])
		clean_exit(game, "Problem loading textures\n");
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, OPEN, s, s);
	if (!game->exit[1])
		clean_exit(game, "Problem loading textures\n");
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, s, s);
	if (!game->collect)
		clean_exit(game, "Problem loading textures\n");
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, s, s);
	if (!game->floor)
		clean_exit(game, "Problem loading textures\n");
	game->player[0] = mlx_xpm_file_to_image(game->mlx, PLAYER_R, s, s);
	if (!game->player[0])
		clean_exit(game, "Problem loading textures\n");
	game->player[1] = mlx_xpm_file_to_image(game->mlx, PLAYER_D, s, s);
	if (!game->player[1])
		clean_exit(game, "Problem loading textures\n");
	game->player[2] = mlx_xpm_file_to_image(game->mlx, PLAYER_L, s, s);
	if (!game->player[2])
		clean_exit(game, "Problem loading textures\n");
	next(game, s);
}
