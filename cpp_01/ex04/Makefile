SRC =	main.cpp 
OBJS = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
TESTFLAGS = -Wall -Wextra -Werror -pedantic
NAME = mr_replace
TEST = tester

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

test:
	$(CXX) $(TESTFLAGS) tests.cpp -o $(TEST)

clean:
	$(RM) $(OBJS) test_*

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean $(NAME) test

.PHONY: all clean fclean re
