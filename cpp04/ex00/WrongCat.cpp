#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "\e[0;105mWrongCat::\e[0m Default constructor called for " << _type << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "\e[0;105mWrongCat::\e[0m Parameteried constructor called for " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source)
{
    _type = source._type;
    std::cout << "\e[0;105mWrongCat::\e[0m Copy constructor called for " << _type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
    if (this != &source)
        WrongAnimal::operator=(source);
	
    std::cout << "\e[0;105mWrongCat::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\e[0;105mWrongCat::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string WrongCat::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void WrongCat::makeSound(void)
{
    std::cout << _type << "\e[1;35msays: Miaaaaau miaau!\e[0m" << std::endl;
}