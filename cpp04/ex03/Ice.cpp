#include "unityBuildHeader.hpp"

Ice::Ice(void) : AMateria("ice"), _type("ice")
{
    // std::cout << "\e[0;103mIce::\e[0m Default constructor called for " << _type << std::endl;
}

Ice::Ice(std::string const &type) : AMateria("ice"), _type(type)
{
    // std::cout << "\e[0;103mIce::\e[0m Parameterized constructor called for " << _type << std::endl;
}

Ice::Ice(const Ice &source) : AMateria("ice"), _type(source._type)
{
    // std::cout << "\e[0;103mIce::\e[0m Copy constructor called for " << _type << std::endl;
}

Ice &Ice::operator=(const Ice &source)
{
    if (this != &source)
       const std::string _type = source._type;
	
    // std::cout << "\e[0;103mIce::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Ice::~Ice()
{
    // std::cout << "\e[0;103mIce::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

Ice *Ice::clone(void) const// returns a new instance of the same type
{
    // Ice *clone;
    // std::cout << "wut" <<std::endl;
    // clone = new Ice();
    // std::cout << "Ice:: Cloning" << clone->getType() << std::endl;
    // return clone;
    Ice *clone = new Ice(*this);
    // clone->_type = source->_type;
    // std::cout << "Ice:: Cloning" << std::endl;
    return clone;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}