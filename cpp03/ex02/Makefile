NAME	:= repetitive

all:	$(NAME)

$(NAME): main.cpp
		g++ -Wall -Wextra -Werror -std=c++98 main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
