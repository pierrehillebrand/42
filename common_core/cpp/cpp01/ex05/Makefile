CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = harl

SRC = main.cpp \
	Harl.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean \
	all