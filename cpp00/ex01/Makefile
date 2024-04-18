NAME	:= phoneBook

all:	$(NAME)

$(NAME): PhoneBook.cpp
		g++ -Wall -Wextra -Werror -std=c++98 PhoneBook.cpp Contact.cpp main.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re