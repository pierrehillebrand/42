# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:05:08 by lfarhi            #+#    #+#              #
#    Updated: 2024/12/04 14:52:49 by lfarhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### COLORS ###########
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
CLEAR_LINE = \033[2K
##############################

NAME = libft.a
SRC = ./
SRCS =

#############################  ASCII  ##########################################
SRCS += ${SRC}Ascii/ft_isalnum.c ${SRC}Ascii/ft_isalpha.c
SRCS += ${SRC}Ascii/ft_isascii.c ${SRC}Ascii/ft_isdigit.c ${SRC}Ascii/ft_isspace.c
SRCS += ${SRC}Ascii/ft_isprint.c
#############################  ITERATOR  ###########################################
SRCS += ${SRC}Iterator/Array/array_iterator.c
SRCS += ${SRC}Iterator/List/list_iterator.c
#############################  LIST   ###########################################
SRCS += ${SRC}List/ft_lstadd_back.c ${SRC}List/ft_lstadd_front.c
SRCS += ${SRC}List/ft_lstclear.c ${SRC}List/ft_lstdelone.c ${SRC}List/ft_lstiter.c
SRCS += ${SRC}List/ft_lstlast.c ${SRC}List/ft_lstmap.c
SRCS += ${SRC}List/ft_lstnew.c ${SRC}List/ft_lstsize.c ${SRC}List/ft_lstremove.c
SRCS += ${SRC}List/ft_lstget.c ${SRC}List/ft_lstgetv.c ${SRC}List/ft_lstset.c
SRCS += ${SRC}List/ft_lstindex.c ${SRC}List/ft_lstindexv.c
SRCS += ${SRC}List/ft_lstinsert.c
#############################  MEMORY ###########################################
SRCS += ${SRC}Memory/ft_bzero.c ${SRC}Memory/ft_calloc.c
SRCS += ${SRC}Memory/ft_memchr.c ${SRC}Memory/ft_memcmp.c
SRCS += ${SRC}Memory/ft_memcpy.c ${SRC}Memory/ft_memmove.c
SRCS += ${SRC}Memory/ft_memset.c ${SRC}Memory/ft_realloc.c
#############################  PUT  ###########################################
SRCS += ${SRC}Put/ft_putchar_fd.c ${SRC}Put/ft_putstr_fd.c
SRCS += ${SRC}Put/ft_putendl_fd.c ${SRC}Put/ft_putnbr_fd.c
#############################  STRING  ###########################################
SRCS += ${SRC}String/ft_strlcat.c ${SRC}String/ft_strlcpy.c
SRCS += ${SRC}String/ft_strlen.c ${SRC}String/ft_strncmp.c ${SRC}String/ft_strnstr.c
SRCS += ${SRC}String/ft_strrchr.c ${SRC}String/ft_tolower.c
SRCS += ${SRC}String/ft_toupper.c ${SRC}String/ft_striteri.c
SRCS += ${SRC}String/ft_substr.c ${SRC}String/ft_strjoin.c
SRCS += ${SRC}String/ft_strtrim.c ${SRC}String/ft_strmapi.c
SRCS += ${SRC}String/ft_strchr.c ${SRC}String/ft_strdup.c
SRCS += ${SRC}String/ft_strcdup.c ${SRC}String/ft_strcmp.c
#############################  UTILS  ###########################################
SRCS += ${SRC}Utils/ft_split.c ${SRC}Utils/ft_itoa.c
SRCS += ${SRC}Utils/ft_str_itoa.c
SRCS += ${SRC}Utils/ft_atoi.c
#############################  PRINTF  ###########################################
SRCS += ${SRC}/Printf/srcs/ft_format.c
SRCS += ${SRC}/Printf/srcs/ft_printf.c
SRCS += ${SRC}/Printf/srcs/formats/form_hexa_lower.c
SRCS += ${SRC}/Printf/srcs/formats/form_hexa_upper.c
SRCS += ${SRC}/Printf/srcs/formats/form_pointer.c
SRCS += ${SRC}/Printf/srcs/formats/form_string.c
SRCS += ${SRC}/Printf/srcs/formats/form_char.c
SRCS += ${SRC}/Printf/srcs/formats/form_unsigned.c
SRCS += ${SRC}/Printf/srcs/formats/form_percent.c
SRCS += ${SRC}/Printf/srcs/formats/form_int.c
SRCS += ${SRC}/Printf/srcs/ft_flags.c
SRCS += ${SRC}/Printf/srcs/sp_libft/sp_putnbr.c
SRCS += ${SRC}/Printf/srcs/sp_libft/sp_putnbr_n.c
SRCS += ${SRC}/Printf/srcs/sp_libft/sp_putstr.c
SRCS += ${SRC}/Printf/srcs/sp_libft/sp_putnbr_base.c
SRCS += ${SRC}/Printf/srcs/sp_libft/sp_maxi.c
################################################################################


OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -g3

TOTAL_FILES := $(words ${SRCS})
CURRENT_FILES = 0

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "${GREEN}Compiled: ${NAME}${RESET}"

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

%.o: %.c
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(eval PROGRESS=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	@printf "${CLEAR_LINE}${PROGRESS}%% "
	@printf "${GREEN}Compiling: %s${RESET}\n" $<
	@${CC} ${CFLAGS} ${LFLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re bonus