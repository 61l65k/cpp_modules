SRC =	main.cpp ClapTrap.cpp 
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = ClapFight
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CPPFLAGS = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
