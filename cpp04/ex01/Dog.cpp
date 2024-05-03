#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _type("Dog")
{
    std::cout << "\e[0;104mDog::\e[0m Default constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type), _type(type)
{
    std::cout << "\e[0;104mDog::\e[0m Parameterized constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &source) : Animal(source), _type(source._type)
{
    std::cout << "\e[0;105mDog::\e[0m Copy constructor called for " << _type << std::endl;
    _brain = new Brain(*source._brain);// Create a new instance of Brain and copy its content
}

Dog &Dog::operator=(const Dog &source)
{
    if (this != &source)
    {
        Animal::operator=(source);// Call the base class assignment operator
        _type = source._type;// Perform (deep copy) for Dog-specific members
        delete _brain;// Delete current _brain if any
        _brain = new Brain(*source._brain);// Create a new instance of Brain and copy its content
    }
    std::cout << "\e[0;105mDog::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Dog::~Dog()
{
    std::cout << "\e[0;104mDog::\e[0m Destructor called for " << _type << std::endl;
    delete _brain;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string Dog::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void Dog::makeSound(void) const
{
    std::cout << "\e[1;34mWoof woof!\e[0m" << std::endl;
}

void Dog::addIdea(const std::string& idea)
{
    int i = 0;

    while (i < 100)
    {
        if (_brain->ideaIsEmpty(i))
            _brain->addIdeaAtIndex(idea, i);
        i++;
    }
    if (i >= 100)
        std::cout << "Brain is full! Ignoring the new idea." << std::endl;
}

void Dog::printIdeas(void) const
{
    _brain->getIdeas();
}