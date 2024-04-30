#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _type("Dog")
{
    std::cout << "\e[0;104mDog::\e[0m Default constructor called for " << _type << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _type(type)
{
    std::cout << "\e[0;104mDog::\e[0m Parameteried constructor called for " << _type << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source), _type(source._type)
{
    std::cout << "\e[0;104mDog::\e[0m Copy constructor called for " << _type << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
    if (this != &source)
    {
         Animal::operator=(source);
         _type = source._type;
    }
	std::cout << "\e[0;104mDog::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Dog::~Dog()
{
    std::cout << "\e[0;104mDog::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string Dog::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void Dog::makeSound(void) const
{
    std::cout << _type << "\e[1;34m says: Woof woof!\e[0m" << std::endl;
}