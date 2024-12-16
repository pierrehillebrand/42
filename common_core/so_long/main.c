/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:16 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/27 11:14:53 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	test_deplacement(int pos_x, int pos_y, t_game *game, int type)
{
	if (game->map[pos_y][pos_x] == '1')
		return (0);
	if (game->map[pos_y][pos_x] == 'C')
		game->collectibles--;
	if (game->collectibles == 0)
		game->is_open = 1;
	if (game->map[pos_y][pos_x] == 'E' && game->collectibles == 0)
		return (mlx_loop_end(game->mlx));
	game->map[game->pos_y][game->pos_x] = '0';
	if (game->is_on_exit)
	{
		game->map[game->pos_y][game->pos_x] = 'E';
		game->is_on_exit = 0;
	}
	if (game->map[pos_y][pos_x] == 'E')
		game->is_on_exit = 1;
	game->map[pos_y][pos_x] = 'P';
	game->pos_x = pos_x;
	game->pos_y = pos_y;
	put_map(game);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->player[type], game->pos_x * 32, game->pos_y * 32);
	game->moves++;
	putnbr(game->moves);
	return (1);
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KESC)
		mlx_loop_end(game->mlx);
	else if (keycode == KA)
		test_deplacement(game->pos_x - 1, game->pos_y, game, 2);
	else if (keycode == KD)
		test_deplacement(game->pos_x + 1, game->pos_y, game, 0);
	else if (keycode == KS)
		test_deplacement(game->pos_x, game->pos_y + 1, game, 1);
	else if (keycode == KW)
		test_deplacement(game->pos_x, game->pos_y - 1, game, 3);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
		return (-1);
	game = ft_calloc(sizeof(t_game), 1);
	map(av[1], game);
	if (game->height * 32 > 1080 || game->width * 32 > 1920)
		clean_exit(game, "The map is too big\n");
	game->img_s = 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, "The initialisation failed\n");
	load_textures(game, &game->img_s);
	game->window = mlx_new_window(game->mlx, game->width * 32, \
	game->height * 32, "Hello there!");
	if (!game->window)
		clean_exit(game, "The window did not open\n");
	put_map(game);
	mlx_hook(game->window, EVENT_KPRESS, MASK_KPRESS, keypress, game);
	mlx_hook(game->window, EVENT_DESTROY, NO_MASK, mlx_loop_end, game->mlx);
	mlx_loop(game->mlx);
	cleanup(game);
}
