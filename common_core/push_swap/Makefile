CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
NAME_BONUS = checker

SRCS = \
	test_arguments/maincheck.c \
	test_arguments/int_dest.c \
	utils/abs.c \
	utils/clean_exit.c \
	utils/ft_strlen.c \
	utils/ft_calloc.c \
	utils/ft_putstr.c \
	utils/linked_utils.c \
	utils/loop.c \
	utils/test_best.c \
	resolution/start.c \
	resolution/process.c \
	resolution/rotate_finish.c \
	main.c \

SRCS_BONUS = \
	test_arguments/maincheck.c \
	test_arguments/int_dest.c \
	utils/ft_putstr.c \
	utils/linked_utils.c \
	utils/loop.c \
	utils/ft_calloc.c \
	utils/clean_exit.c \
	utils/ft_strcmp.c \
	utils/ft_strlen.c \
	utils/get_next_line.c \
	utils/get_next_line_utils.c \
	check/main_checker.c \

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) :
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

clean :

fclean : 
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean \
	all
