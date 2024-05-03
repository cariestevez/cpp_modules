#include "Animal.hpp"

Animal::Animal(void) : _type("an animal")
{
    std::cout << "\e[0;103mAnimal::\e[0m Default constructor called for " << _type << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "\e[0;103mAnimal::\e[0m Parameterized constructor called for " << _type << std::endl;
}

Animal::Animal(const Animal &source) :  _type(source._type)
{
    std::cout << "\e[0;103mAnimal::\e[0m Copy constructor called for " << _type << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
    if (this != &source)
        _type = source._type;
	
    std::cout << "\e[0;103mAnimal::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Animal::~Animal()
{
    std::cout << "\e[0;103mAnimal::\e[0m Destructor called for " << _type << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string Animal::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void Animal::makeSound(void) const
{
    std::cout << "\e[1;33mIs confused and doesn't know what to say...\e[0m" << std::endl;
}

void Animal::addIdea(const std::string& idea)
{
    (void)idea;
    std::cout << "I have no brain for ideas" << std::endl;
}

void Animal::printIdeas(void) const
{
    std::cout << "You can get nothing out of a brainles being" << std::endl;
}