CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_printf.c \
       ft_putchar.c \
       ft_putnum.c \
       ft_putnum2.c \
       ft_putpointer.c \
       ft_putstr.c \
       ft_putunum.c \
       ft_putxnum.c \
       trucs.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
clean : 
	rm -rf $(OBJS)

bonus : all

fclean : clean
	rm -rf $(NAME)

re : fclean \
	all

.PHONY: bonus all clean flclean re
