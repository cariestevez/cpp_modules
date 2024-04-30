NAME	:= BraiiiiiiinnnzzzZ

all:	$(NAME)

$(NAME): main.cpp
		c++ -Wall -Wextra -Werror -std=c++98 main.cpp Zombie.cpp newZombie.cpp randomChump.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re