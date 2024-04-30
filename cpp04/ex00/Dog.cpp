#include "Dog.hpp"

Dog::Dog(void)//: type("")
{
    std::cout << "\e[0;104mDog::\e[0m Default constructor called for " << type << std::endl;
}

Dog::Dog(std::string type) : type(type)
{
    std::cout << "\e[0;104mDog::\e[0m Parameteried constructor called for " << type << std::endl;
}

Dog::Dog(const Dog &source)
{
    type = source.type;
    std::cout << "\e[0;104mDog::\e[0m Copy constructor called for " << type << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
    if (this != &source)
        type = source.type;
	std::cout << "\e[0;104mDog::\e[0m Assignment operator used for " << type << std::endl;
	return (*this);
}

Dog::~Dog()
{
    std::cout << "\e[0;104mDog::\e[0m Destructor called for " << type << std::endl;
}

void Dog::makeSound(void)
{
    std::cout << type << "\e[1;34msays: Woof woof!\e[0m" << std::endl;
}