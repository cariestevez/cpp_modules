#include "Animal.hpp"

Animal::Animal(void)//: type("")
{
    std::cout << "\e[0;103mAnimal::\e[0m Default constructor called for " << type << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "\e[0;103mAnimal::\e[0m Parameteried constructor called for " << type << std::endl;
}

Animal::Animal(const Animal &source)
{
    type = source.type;
    std::cout << "\e[0;103mAnimal::\e[0m Copy constructor called for " << type << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
    if (this != &source)
        type = source.type;
	std::cout << "\e[0;103mAnimal::\e[0m Assignment operator used for " << type << std::endl;
	return (*this);
}

Animal::~Animal()
{
    std::cout << "\e[0;103mAnimal::\e[0m Destructor called for " << type << std::endl;
}

void Animal::makeSound(void) {}
// {
//     std::cout << type << "\e[1;33mIs confused and doesn't know what to say...\e[0m" << std::endl;
// }