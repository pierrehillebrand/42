/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:40:09 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/03 10:40:10 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_exit_b(t_game *game, char *error_msg)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map, game->height);
		destroy_images_b(game);
		free(game);
	}
	ft_putstr("Error\n");
	ft_putstr(error_msg);
	exit(-1);
}

void	clean_exit(t_game *game, char *error_msg)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map, game->height);
		destroy_images(game);
		free(game);
	}
	ft_putstr("Error\n");
	ft_putstr(error_msg);
	exit(-1);
}
