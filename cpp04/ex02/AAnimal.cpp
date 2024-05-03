#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("an animal")
{
    std::cout << "\e[0;103mAAnimal::\e[0m Default constructor called for " << _type << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "\e[0;103mAAnimal::\e[0m Parameterized constructor called for " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal &source) :  _type(source._type)
{
    std::cout << "\e[0;103mAAnimal::\e[0m Copy constructor called for " << _type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mAAnimal::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "\e[0;103mAAnimal::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string AAnimal::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

//will be ignored since the fucntion is being declared as pure virtual
void AAnimal::makeSound(void) const
{
    std::cout << "\e[1;33mIs confused and doesn't know what to say...\e[0m" << std::endl;
}

void AAnimal::addIdea(const std::string& idea)
{
    (void)idea;
    std::cout << "I have no brain for ideas" << std::endl;
}

void AAnimal::printIdeas(void) const
{
    std::cout << "You can get nothing out of a brainles being" << std::endl;
}