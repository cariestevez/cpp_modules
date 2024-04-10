NAME	:= phonebook

all:	$(NAME)

$(NAME): PhoneBook.cpp
		c++ -Wall -Wextra -Werror -std=c++98 PhoneBook.cpp Contact.cpp main.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

re:	clean all

.PHONY: all clean re