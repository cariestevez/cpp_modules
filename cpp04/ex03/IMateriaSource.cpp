#include "unityBuildHeader.hpp"
 
IMateriaSource::~IMateriaSource()
{
    std::cout << "\e[0;103mIMateriaSource::\e[0m Destructor called " << std::endl;
}

// virtual void learnMateria(AMateria*) = 0;
// virtual AMateria* createMateria(std::string const & type) = 0;