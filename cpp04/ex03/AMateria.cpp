#include "AMateria.hpp"

AMateria::AMateria(void) : _type("just A Materia")
{
    std::cout << "\e[0;103mAMateria::\e[0m Default constructor called for " << _type << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "\e[0;103mAMateria::\e[0m Parameterized constructor called for " << _type << std::endl;
}

AMateria::AMateria(const AMateria &source) :  _type(source._type)
{
    std::cout << "\e[0;103mAMateria::\e[0m Copy constructor called for " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mAMateria::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
    std::cout << "\e[0;103mAMateria::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

std::string const &AMateria::getType() const //Returns the materia type
{
    return _type;
}
    
//////////////////////////////////////////////////////////////////////////////////////

//virtual AMateria* clone() const = 0;

void AMateria::use(ICharacter& target)
{
    // Ice: "* shoots an ice bolt at <name> *"
    // Cure: "* heals <name>’s wounds *
}