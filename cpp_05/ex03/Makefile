SRC =	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic
NAME = keepsigning
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CPPFLAGS = -Wall -Wextra -Werror -I headers
endif

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
