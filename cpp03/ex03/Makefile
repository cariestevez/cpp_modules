NAME = diamond

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
#-Wshadow -Wno-shadow
CPP = c++

SRC = ClapTrap ScavTrap FragTrap DiamondTrap main
OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
