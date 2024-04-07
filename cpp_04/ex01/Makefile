SRC =	main.cpp srcs/Animal.cpp srcs/Cat.cpp srcs/Dog.cpp srcs/WrongAnimal.cpp srcs/WrongCat.cpp srcs/Brain.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic -I includes -I headers
NAME = smart_zoo
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
