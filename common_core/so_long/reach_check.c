/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:40:56 by phillebr          #+#    #+#             */
/*   Updated: 2024/09/03 11:40:57 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_spe(char c, int type)
{
	if (!type)
	{
		if (c == '0')
			return (1);
	}
	if (c == 'E' || c == 'C')
		return (1);
	return (0);
}

static int	final_verif(char **dup_map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (is_spe(dup_map[i][j], 1))
				return (clean_map(dup_map, height), 0);
			j++;
		}
		i++;
	}
	return (clean_map(dup_map, height), 1);
}

static char	**map_duplication(t_game *game, char **map, int height, int width)
{
	int		i;
	int		j;
	char	**dup_map;

	dup_map = (char **)ft_calloc(sizeof(char *), height + 1);
	if (!dup_map)
		return (clean_exit(game, "Allocation error\n"), NULL);
	i = -1;
	while (++i < height)
	{
		dup_map[i] = (char *)ft_calloc(sizeof(char), width);
		if (!dup_map[i])
		{
			clean_map(dup_map, game->height);
			clean_exit(game, "Allocation error\n");
		}
	}
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			dup_map[i][j] = map[i][j];
	}
	return (dup_map);
}

static int	place(t_game *game, char **map, int i, int j)
{
	int	count;

	count = 0;
	if (i > 0 && is_spe(map[i - 1][j], 0))
	{
		map[i - 1][j] = 'P';
		count++;
	}
	if (i < game->height && is_spe(map[i + 1][j], 0))
	{
		count++;
		map[i + 1][j] = 'P';
	}
	if (j < game->width && is_spe(map[i][j + 1], 0))
	{
		count++;
		map[i][j + 1] = 'P';
	}
	if (j > 0 && is_spe(map[i][j - 1], 0))
	{
		count++;
		map[i][j - 1] = 'P';
	}
	return (count);
}

int	reach_check(t_game *game)
{
	char	**dup_map;
	int		i;
	int		j;
	int		test;

	dup_map = map_duplication(game, game->map, game->height, game->width);
	test = 1;
	while (test != 0)
	{
		test = 0;
		i = 0;
		while (i < game->height)
		{
			j = 0;
			while (j < game->width)
			{
				if (dup_map[i][j] == 'P')
					test += place(game, dup_map, i, j);
				j++;
			}
			i++;
		}
	}
	return (final_verif(dup_map, game->height, game->width));
}
