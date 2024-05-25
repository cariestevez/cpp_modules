NAME = typeinfo

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-unused-variable
#-Wshadow -Wno-shadow
CXX = c++

SRC = Base main
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
