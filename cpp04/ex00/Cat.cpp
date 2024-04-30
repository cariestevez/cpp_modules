#include "Cat.hpp"

Cat::Cat(void)//: type("")
{
    std::cout << "\e[0;105mCat::\e[0m Default constructor called for " << type << std::endl;
}

Cat::Cat(std::string type) : type(type)
{
    std::cout << "\e[0;105mCat::\e[0m Parameteried constructor called for " << type << std::endl;
}

Cat::Cat(const Cat &source)
{
    type = source.type;
    std::cout << "\e[0;105mCat::\e[0m Copy constructor called for " << type << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
    if (this != &source)
        type = source.type;
	std::cout << "\e[0;105mCat::\e[0m Assignment operator used for " << type << std::endl;
	return (*this);
}

Cat::~Cat()
{
    std::cout << "\e[0;105mCat::\e[0m Destructor called for " << type << std::endl;
}

void Cat::makeSound(void)
{
    std::cout << type << "\e[1;35msays: Miaaaaau miaau!\e[0m" << std::endl;
}