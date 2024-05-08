#include "unityBuildHeader.hpp"

Cure::Cure(void) : AMateria("cure"), _type("cure")
{
    // std::cout << "\e[0;103mCure::\e[0m Default constructor called for " << _type << std::endl;
}

Cure::Cure(std::string const &type) : AMateria("cure"), _type(type)
{
    // std::cout << "\e[0;103mCure::\e[0m Parameterized constructor called for " << _type << std::endl;
}

Cure::Cure(const Cure &source) : AMateria("cure"), _type(source._type)
{
    // std::cout << "\e[0;103mCure::\e[0m Copy constructor called for " << _type << std::endl;
}

Cure &Cure::operator=(const Cure &source)
{
    if (this != &source)
       AMateria::operator=(source);
	
    // std::cout << "\e[0;103mCure::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Cure::~Cure()
{
    // std::cout << "\e[0;103mCure::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

Cure *Cure::clone(void) const// returns a new instance of the same type
{
    // Cure *clone = new Cure(*this);
    // // std::cout << "Cure:: Cloning cure" << std::endl;
    // return clone;
    return new Cure(*this);
}

// void Cure::use(ICharacter &target)
// {
//     std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
// }