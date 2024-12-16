CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = pipex
NAME_BONUS = pipex_bonus

SRC = \
	main.c \
	child.c \
	clean/clean_path.c \
	clean/close_fd.c \
	utils/ft_calloc.c \
	utils/ft_putstr.c \
	utils/ft_split.c \
	utils/ft_strjoin.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \

SRC_BONUS = \
	main_bonus.c \
	child.c \
	clean/clean_path.c \
	clean/close_fd.c \
	utils/ft_calloc.c \
	utils/ft_putstr.c \
	utils/ft_split.c \
	utils/ft_strjoin.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean \
	all

.PHONY: all clean fclean re
