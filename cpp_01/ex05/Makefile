SRC =	main.cpp Harl.cpp
OBJS = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = harlem
TEST = tester

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
