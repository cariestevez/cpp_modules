NAME	:= sed_is_for_losers

all:	$(NAME)

$(NAME): main.cpp
		g++ -g -Wall -Wextra -Werror -std=c++98 main.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re