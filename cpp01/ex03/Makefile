NAME	:= unnecessary_violence

all:	$(NAME)

$(NAME): main.cpp
		g++ -g -Wall -Wextra -Werror -std=c++98 main.cpp Weapon.cpp HumanA.cpp HumanB.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re