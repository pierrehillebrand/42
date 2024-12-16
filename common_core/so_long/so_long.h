/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:18:33 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/30 17:20:58 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define KESC 65307
# define KW 119
# define KA 97
# define KS 115
# define KD 100

# define MASK_KPRESS 0x01
# define NO_MASK 0

# define EVENT_KPRESS 2
# define EVENT_DESTROY 17

# define BUFFER_SIZE 1
# define ENEMY		"./textures/enemy.xpm"
# define WALL		"./textures/wall.xpm"
# define COLLECT	"./textures/collectible.xpm"
# define FLOOR		"./textures/floor.xpm"
# define PLAYER_D	"./textures/player_down.xpm"
# define PLAYER_R	"./textures/player_right.xpm"
# define PLAYER_L	"./textures/player_left.xpm"
# define PLAYER_U	"./textures/player_up.xpm"
# define OPEN		"./textures/open_exit.xpm"
# define CLOSED		"./textures/closed_exit.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		height;
	int		width;
	int		img_s;
	void	*player[4];
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit[2];
	void	*enemy;
	int		pos_x;
	int		pos_y;
	int		collectibles;
	int		is_open;
	int		is_on_exit;
	int		moves;
	char	*character;
}	t_game;

void		map(char *path, t_game *game);
void		map_b(char *path, t_game *game);
void		clean_exit(t_game *game, char *error_message);
int			reach_check(t_game *game);
void		clean_map(char **map, int height);
int			ft_putstr(char *str);
int			cleanup(t_game *game);
int			cleanup_b(t_game *game);
void		load_textures(t_game *game, int *s);
void		put_map(t_game *game);
void		put_map_b(t_game *game);
void		destroy_images(t_game *game);
void		putnbr(long x);
void		clean_exit_b(t_game *game, char *error_msg);
void		load_textures_b(t_game *game, int *s);
void		destroy_images_b(t_game *game);
char		*ft_itoa(int x, t_game *game);

/* GET NEXT LINE */
char		*get_next_line(int fd);
int			ft_strlen(char *str);
void		*ft_calloc(size_t size, size_t nbr);
char		*ft_dup2(char *str, size_t size);
char		*dupfinal(char *str);
char		*get_next_line(int fd);
long long	ft_strrchr(const char *s, int c);

#endif
