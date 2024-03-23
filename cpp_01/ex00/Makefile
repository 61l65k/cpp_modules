SRC =	main.cpp newZombie.cpp \
		randomChump.cpp  Zombie.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = dumbie

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
