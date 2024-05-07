#include "unityBuildHeader.hpp"

AMateria::AMateria(void) : _type("just A Materia")
{
    // std::cout << "\e[0;103mAMateria::\e[0m Default constructor called for " << _type << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    // std::cout << "\e[0;103mAMateria::\e[0m Parameterized constructor called for " << _type << std::endl;
}

AMateria::AMateria(const AMateria &source) :  _type(source._type)
{
    // std::cout << "\e[0;103mAMateria::\e[0m Copy constructor called for " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &source)
{
    if (this != &source)
        const std::string _type = source._type;
	
    // std::cout << "\e[0;103mAMateria::\e[0m Assignment operator used for " << _type << std::endl;
	
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "\e[0;103mAMateria::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

std::string const &AMateria::getType() const //Returns the materia type
{
    return _type;
}
    
//////////////////////////////////////////////////////////////////////////////////////

//virtual AMateria* clone() const = 0;

void AMateria::use(ICharacter &target)
{
    std::cout << "* Doesn't know what to do with " << target.getName() << " *" << std::endl;

}