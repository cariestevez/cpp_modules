NAME	:= interface

all:	$(NAME)

$(NAME): main.cpp
		c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o $(NAME)
#-Wshadow -Wno-shadow
clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
