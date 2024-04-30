NAME	:= polymorphism

all:	$(NAME)

$(NAME): main.cpp
		g++ -Wall -Wextra -Werror -std=c++98 main.cpp animal.cpp -o $(NAME)
#-Wshadow -Wno-shadow
clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
