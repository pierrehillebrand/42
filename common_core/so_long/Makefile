CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME = so_long
NAME_BONUS = so_longs

MINILIB_PATH = ./minilibx
MINILIB = $(MINILIB_PATH)/libmlx.a
SRC = 	\
	main.c \
	map.c \
	reach_check.c \
	get_next_line.c \
	get_next_line_utils.c \
	put_map.c \
	utils/ft_putstr.c \
	utils/load_textures.c \
	utils/putnbr.c \
	clean/cleanup.c \
	clean/clean_map.c \
	clean/clean_exit.c \

SRC_BONUS = \
	main_bonus.c \
	map_b.c \
	reach_check.c \
	get_next_line.c \
	get_next_line_utils.c \
	put_map.c \
	utils/ft_putstr.c \
	utils/load_textures.c \
	utils/putnbr.c \
	clean/cleanup.c \
	clean/clean_map.c \
	clean/clean_exit.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(MINILIB_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MINILIB) $(LDFLAGS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) :  $(OBJ_BONUS)
	make -C $(MINILIB_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MINILIB) $(LDFLAGS) -o $(NAME_BONUS)
clean :
	make clean -C $(MINILIB_PATH)
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
