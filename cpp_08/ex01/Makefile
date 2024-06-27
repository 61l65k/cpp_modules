SRC =	main.cpp Span.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = spanner
UNAME := $(shell uname)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re