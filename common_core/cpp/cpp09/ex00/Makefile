CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = btc

SRC = main.cpp \
	BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

all : $(SRC) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	all
