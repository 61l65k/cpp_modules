NAME=megaphone
CC=c++
CFLAGS=-Wall -Wextra -Werror --std=c++98

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CC) $(CFLAGS) $(NAME).cpp -o $(NAME)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: clean all fclean
