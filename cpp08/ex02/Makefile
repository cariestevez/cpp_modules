NAME = abomination

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main MutantStack
OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
