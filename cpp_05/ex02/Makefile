SRC =	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic
NAME = formhell
UNAME := $(shell uname)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
