NAME	:= weird

all:	$(NAME)

$(NAME): main.cpp
		g++ -Wall -Wextra -Werror -std=c++98 main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp -o $(NAME)
#-Wshadow -Wno-shadow
clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
