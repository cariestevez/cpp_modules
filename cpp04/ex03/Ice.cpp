#include "Ice.hpp"

Ice::Ice(void) : _type("ice")
{
    std::cout << "\e[0;103mIce::\e[0m Default constructor called for " << _type << std::endl;
}

Ice::Ice(std::string const &type) : _type(type)
{
    std::cout << "\e[0;103mIce::\e[0m Parameterized constructor called for " << _type << std::endl;
}

Ice::Ice(const Ice &source) :  _type(source._type)
{
    std::cout << "\e[0;103mIce::\e[0m Copy constructor called for " << _type << std::endl;
}

Ice &Ice::operator=(const Ice &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mIce::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Ice::~Ice()
{
    std::cout << "\e[0;103mIce::\e[0m Destructor called for " << _type << std::endl;
}


Ice *Ice::clone(const Ice *source)// returns a new instance of the same type
{
    Ice *clone = new Ice;
    clone->_type = source->_type;
    
    return clone;
}

void Ice::use(ICharacter& target)
{
    // Ice: "* shoots an ice bolt at <name> *"
}