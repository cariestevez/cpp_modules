NAME	:= dreamjob

all:	$(NAME)

$(NAME): Account.cpp
		g++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re