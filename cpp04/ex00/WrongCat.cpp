#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong cat"), _type("Wrong cat")
{
    std::cout << "\e[0;105mWrongCat::\e[0m Default constructor called for " << _type << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type), _type("Wrong cat")
{
    std::cout << "\e[0;105mWrongCat::\e[0m Parameterized constructor called for " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source), _type(source._type)
{
    _type = source._type;
    std::cout << "\e[0;105mWrongCat::\e[0m Copy constructor called for " << _type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
    if (this != &source)
    {
        WrongAnimal::operator=(source);
        _type = source._type;
    }
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

void WrongCat::makeSound(void) const
{
    std::cout << "\e[1;35mMiaaaaau miaau!\e[0m" << std::endl;
}