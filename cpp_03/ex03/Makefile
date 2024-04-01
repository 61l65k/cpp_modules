SRC =	main.cpp srcs/ClapTrap.cpp srcs/ScavTrap.cpp srcs/FragTrap.cpp srcs/DiamondTrap.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic -I includes -I headers
NAME = dclapper
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CPPFLAGS = -Wall -Wextra -Werror -I headers
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
