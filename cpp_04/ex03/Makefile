NAME := iface
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -I./headers
SRCS :=	main.cpp \
		srcs/AMateria.cpp \
		srcs/Ice.cpp \
		srcs/Cure.cpp \
		srcs/Character.cpp \
		srcs/MateriaSource.cpp
OBJ := $(SRCS:.cpp=.o)
RM := rm -f

$(NAME) : $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
