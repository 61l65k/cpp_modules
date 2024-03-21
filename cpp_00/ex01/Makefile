NAME=pbook
CC=c++
CPPFLAGS=-Wall -Wextra -Werror --std=c++98 -pedantic
SRCS=		PhoneBook.cpp \
			Contact.cpp \
			main.cpp	\
			handlers.cpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
