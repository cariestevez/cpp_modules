NAME	:= abstract_class

all:	$(NAME)

$(NAME): main.cpp
		c++ -Wall -Wextra -Werror -std=c++98 main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp -o $(NAME)
#-Wshadow -Wno-shadow
clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
