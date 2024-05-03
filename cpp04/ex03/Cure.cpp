#include "Cure.hpp"

Cure::Cure(void) : _type("cure")
{
    std::cout << "\e[0;103mCure::\e[0m Default constructor called for " << _type << std::endl;
}

Cure::Cure(std::string const &type) : _type(type)
{
    std::cout << "\e[0;103mCure::\e[0m Parameterized constructor called for " << _type << std::endl;
}

Cure::Cure(const Cure &source) :  _type(source._type)
{
    std::cout << "\e[0;103mCure::\e[0m Copy constructor called for " << _type << std::endl;
}

Cure &Cure::operator=(const Cure &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mCure::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Cure::~Cure()
{
    std::cout << "\e[0;103mCure::\e[0m Destructor called for " << _type << std::endl;
}

Cure *Cure::clone(const Cure *source)// returns a new instance of the same type
{
    Cure *clone = new Cure;
    clone->_type = source->_type;
    
    return clone;
}

void Cure::use(ICharacter& target)
{
    // Cure: "* heals <name>’s wounds *
}