SRC =	main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic #-fsanitize=address
NAME = beeaspee

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX)  $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
