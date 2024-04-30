NAME	:= harlFilter

all:	$(NAME)

$(NAME): main.cpp
		c++ -g -Wall -Wextra -Werror -std=c++98 main.cpp Harl.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re