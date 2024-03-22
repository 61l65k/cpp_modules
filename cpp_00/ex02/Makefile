SRC = Account.cpp tests.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = cake
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
CPPFLAGS = -Wall -Wextra -pedantic
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
