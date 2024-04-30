NAME	:= fixed02

all:	$(NAME)

$(NAME): main.cpp
		c++ -Wall -Wextra -Werror -std=c++98 main.cpp Fixed.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re
