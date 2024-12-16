/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:17:03 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/30 17:37:52 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_number(t_game *game, int i, int j, int c)
{
	int	e;
	int	p;

	i = -1;
	e = 0;
	p = 0;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				c++;
			else if (game->map[i][j] == 'E')
				e++;
			else if (game->map[i][j] == 'P')
				p++;
		}
	}
	if (c == 0 || e != 1 || p != 1)
		clean_exit_b(game, "The number of special elements is incorrect\n");
	game->collectibles = c;
	if (!reach_check(game))
		clean_exit_b(game, "This map is not beatable\n");
}

static int	is_acceptable(t_game *game, int i, int j, char c)
{
	if (c == 'P')
	{
		game->pos_x = j;
		game->pos_y = i;
		return (1);
	}
	if (c == 'E' || c == '1' || c == '0' || c == 'C' || c == 'X')
		return (1);
	return (0);
}

static void	test_dimensions(t_game *game)
{
	int	line;
	int	row;
	int	c;

	c = 0;
	line = -1;
	while (++line < game->height)
	{
		row = -1;
		while (++row < game->width)
		{
			if (!is_acceptable(game, line, row, game->map[line][row]))
				clean_exit_b(game, "The map contains forbidden characters\n");
			if (line == 0 || line == game->height - 1
				|| row == 0 || row == game->width - 1)
			{
				if (game->map[line][row] != '1')
					clean_exit_b(game, "The map is not closed\n");
			}
		}
		if (ft_strlen(game->map[line]) - (game->map[line] \
		[ft_strlen(game->map[line]) - 1] == '\n') != game->width)
			clean_exit_b(game, "The map is not rectangular\n");
	}
	check_number(game, line, row, c);
}

static int	test_files(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	*entry;

	if (ft_strlen(path) < 4)
		clean_exit_b(game, "File is not valid\n");
	if (!(path[ft_strlen(path) - 1] == 'r' && path[ft_strlen(path) - 2] == 'e'))
		clean_exit_b(game, "Map is not .ber\n");
	if (!(path[ft_strlen(path) - 3] == 'b' && path[ft_strlen(path) - 4] == '.'))
		clean_exit_b(game, "Map is not .ber\n");
	fd = open(path, O_RDONLY);
	if (fd < 3)
		clean_exit(game, "File did not open\n");
	entry = get_next_line(fd);
	i = 0;
	while (entry != NULL)
	{
		free(entry);
		entry = get_next_line(fd);
		i++;
	}
	free(entry);
	close (fd);
	return (i);
}

void	map_b(char *path, t_game *game)
{
	char	**map;
	char	*entry;
	int		fd;
	int		i;

	i = test_files(path, game);
	if (i == 0)
		clean_exit_b(game, "File is empty\n");
	map = (char **)ft_calloc(sizeof(char *), i);
	if (!map)
		clean_exit_b(game, "Allocation Error\n");
	fd = open(path, O_RDONLY);
	if (fd < 3)
		clean_exit_b(game, "File did not open\n");
	i = 0;
	entry = get_next_line(fd);
	while (entry != NULL)
	{
		map[i++] = entry;
		entry = get_next_line(fd);
	}
	game->map = map;
	game->height = i;
	game->width = ft_strlen(map[0]) - 1;
	test_dimensions(game);
}
