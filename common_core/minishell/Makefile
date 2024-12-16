# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 17:53:32 by lfarhi            #+#    #+#              #
#    Updated: 2024/12/10 14:36:38 by lfarhi           ###   ########.fr        #
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

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -lreadline -ltermcap

######### SOURCES #########
SRC = ./srcs/
SRCS = ${SRC}main.c

######### LEXER #########
SRCS += ${SRC}lexer/lexer.c
SRCS += ${SRC}lexer/lexer_init.c
SRCS += ${SRC}lexer/token.c
SRC_TOKENS = ${SRC}lexer/tokens/
SRCS += ${SRC_TOKENS}and.c
SRCS += ${SRC_TOKENS}arg.c
SRCS += ${SRC_TOKENS}arg_aux.c
SRCS += ${SRC_TOKENS}lparen.c
SRCS += ${SRC_TOKENS}newline.c
SRCS += ${SRC_TOKENS}or.c
SRCS += ${SRC_TOKENS}pipe.c
SRCS += ${SRC_TOKENS}redir_heredoc.c
SRCS += ${SRC_TOKENS}redir_in.c
SRCS += ${SRC_TOKENS}redir_out.c
SRCS += ${SRC_TOKENS}redir_out_append.c
SRCS += ${SRC_TOKENS}rparen.c
SRCS += ${SRC_TOKENS}var.c
SRCS += ${SRC_TOKENS}whitespace.c
###########################

########### ENV ###########
SRCS += ${SRC}env/env.c
SRCS += ${SRC}env/env_var.c
###########################

########## PARSER #########
SRCS += ${SRC}parser/parser.c
SRCS += ${SRC}parser/clean/clean_args.c
SRCS += ${SRC}parser/clean/clean_vars.c
SRCS += ${SRC}parser/clean/clean_vars_redir.c
SRCS += ${SRC}parser/clean/clean_whitespace.c
SRCS += ${SRC}parser/syntax.c
###########################

########## LIBFT ##########
LIBFT = libft/libft.a
LIBFT_FLAGS = -L ./libft -I ./libft -lft
LFLAGS += ${LIBFT_FLAGS} -Qunused-arguments
###########################

######## MINISHELL ########
SRCS += ${SRC}minishell/minishell.c
SRCS += ${SRC}minishell/prompt.c
SRCS += ${SRC}minishell/signals.c
###########################

########## EXEC ###########
SRCS += ${SRC}exec/exec.c
SRCS += ${SRC}exec/child.c
SRCS += ${SRC}exec/find_path.c
SRCS += ${SRC}exec/free_args.c
SRCS += ${SRC}exec/redirs.c
SRCS += ${SRC}exec/t_tlist.c
SRCS += ${SRC}exec/is_in.c
SRCS += ${SRC}exec/end_print.c
SRCS += ${SRC}exec/exec_builtin.c
SRCS += ${SRC}exec/builtins/cd.c
SRCS += ${SRC}exec/builtins/echo.c
SRCS += ${SRC}exec/builtins/env.c
SRCS += ${SRC}exec/builtins/exit.c
SRCS += ${SRC}exec/builtins/export.c
SRCS += ${SRC}exec/builtins/print_sorted.c
SRCS += ${SRC}exec/builtins/pwd.c
SRCS += ${SRC}exec/builtins/unset.c
###########################



OBJS = ${SRCS:.c=.o}

TOTAL_FILES := $(words ${SRCS})
CURRENT_FILES = 0

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} -o ${NAME}
	@echo "${GREEN}Compilation of ${NAME} : ${GREEN}Success${RESET}"


bonus: ${NAME}

${LIBFT}:
	@make -C libft

%.o: %.c
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(eval PROGRESS=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	@printf "${CLEAR_LINE}${PROGRESS}%% "
	@printf "${GREEN}Compiling: %s${RESET}\n" $<
	@${CC} ${CFLAGS} ${LFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}
	@make -C libft clean

fclean: clean
	rm -f ${NAME}
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus libft
