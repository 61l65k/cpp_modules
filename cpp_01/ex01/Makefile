SRC =	main.cpp Zombie.cpp zombieHorde.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = dumbiegang
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CPPFLAGS = -Wall -Wextra -Werror -pedantic
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
