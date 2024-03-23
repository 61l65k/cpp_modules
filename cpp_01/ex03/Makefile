SRC =	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJS = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = groupfight

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
