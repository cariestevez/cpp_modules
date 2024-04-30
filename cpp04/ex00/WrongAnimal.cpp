#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)//: _type("")
{
    std::cout << "\e[0;103mWrongAnimal::\e[0m Default constructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "\e[0;103mWrongAnimal::\e[0m Parameteried constructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
    _type = source._type;
    std::cout << "\e[0;103mWrongAnimal::\e[0m Copy constructor called for " << _type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mWrongAnimal::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\e[0;103mWrongAnimal::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string WrongAnimal::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void WrongAnimal::makeSound(void)
{
    std::cout << _type << "\e[1;33mIs confused and doesn't know what to say...\e[0m" << std::endl;
}