NAME=pbook
CXX=c++
CPPFLAGS=-Wall -Wextra -Werror --std=c++98 -pedantic
SRCS=		PhoneBook.cpp \
			Contact.cpp \
			main.cpp \
			handlers.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
