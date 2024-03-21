NAME=phonebook
CC=c++
CFLAGS=-Wall -Wextra -Werror --std=c++98
SRCS=		PhoneBook.cpp \
			Contact.cpp \
			main.cpp

HEADERS=	PhoneBook.hpp \
			Contact.hpp


all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(HEADERS)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
