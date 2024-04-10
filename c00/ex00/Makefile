NAME	:= megaphone

all:	$(NAME)

$(NAME): megaphone.cpp
		c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re