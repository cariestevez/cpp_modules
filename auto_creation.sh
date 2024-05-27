#!/bin/bash
echo -e "insert directory name please:"
read the_directory
mkdir -p $the_directory
cd $the_directory
echo -e "type the desired name of your executable:"
read executable_name
echo -e "insert number of classes to be created:"
read class_amount
source_files="main"
while [ $class_amount -gt 0 ]
do
    echo -e "insert name of class:"
    read class_name
    echo "#include \"$class_name.hpp\"" >> main.cpp
    source_files="$source_files $class_name"
    class_name_upper=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')
    cat << EOF > "$class_name.hpp"
#ifndef ${class_name_upper}_HPP
#define ${class_name_upper}_HPP

#include <iostream>
#include <string>

class $class_name
{
    private:

    protected:

    public:
        $class_name();
        $class_name(const $class_name &source);
        $class_name &operator=(const $class_name &source);
        ~$class_name();
};

#endif // ${class_name_upper}_HPP
EOF
    cat << EOF > "$class_name.cpp"
#include "$class_name.hpp"

$class_name::$class_name(void)
{
    std::cout << "\e[0;103m$class_name::\e[0m Default constructor called" << std::endl;
}

$class_name::$class_name(const $class_name &source)
{
    std::cout << "\e[0;103m$class_name::\e[0m Copy constructor called" << std::endl;
}

$class_name &$class_name::operator=(const $class_name &source)
{
    if (this != &source)
        //code
	
    std::cout << "\e[0;103m$class_name::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

$class_name::~$class_name()
{
    std::cout << "\e[0;103m$class_name::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////
EOF
    class_amount=$((class_amount - 1))
done
cat << EOF >> main.cpp

int main()
{
    //code
    return 0;
}
EOF
cat << EOF > Makefile
NAME = $executable_name

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = $source_files
OBJ = \$(SRC:=.o)

all: \$(NAME)

\$(NAME): \$(OBJ)
	\$(CXX) \$(OBJ) -o \$(NAME)

%.o: %.cpp
	\$(CXX) \$(CXXFLAGS) -c \$< -o \$@

clean:
	\$(RM) \$(OBJ)

fclean: clean
	\$(RM) \$(NAME)

re: fclean all

.PHONY: all fclean re
EOF
