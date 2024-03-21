NAME=megaphone
CC=c++
CPPFLAGS=-Wall -Wextra -Werror --std=c++98

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CC) $(CPPFLAGS) $(NAME).cpp -o $(NAME)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
