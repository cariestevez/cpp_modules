NAME = convert

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-unused-variable
#-O0 -Wno-unused-variable -Wunused-function
#-Wshadow -Wno-shadow
CXX = c++

SRC = ScalarConverter main
OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.CXX
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
