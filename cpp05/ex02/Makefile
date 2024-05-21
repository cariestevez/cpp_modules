NAME = exception

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
#-Wshadow -Wno-shadow
CXX = c++

SRC = Bureaucrat AForm  ShrubberyCreationForm RobotomyRequestForm  PresidentialPardonForm main
OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.CXX
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
