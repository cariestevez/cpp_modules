#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), _type("Cat")
{
    std::cout << "\e[0;105mCat::\e[0m Default constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Cat::Cat(std::string type) : AAnimal(type), _type(type)
{
    std::cout << "\e[0;105mCat::\e[0m Parameterized constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &source) : AAnimal(source), _type(source._type)
{
    std::cout << "\e[0;105mCat::\e[0m Copy constructor called for " << _type << std::endl;
    _brain = new Brain(*source._brain);// Create a new instance of Brain and copy its content
}

Cat &Cat::operator=(const Cat &source)
{
    if (this != &source)
    {
        AAnimal::operator=(source);// Call the base class assignment operator
        _type = source._type;// Perform (deep copy) for Cat-specific members
        delete _brain;// Delete current _brain if any
        _brain = new Brain(*source._brain);// Create a new instance of Brain and copy its content
    }
    std::cout << "\e[0;105mCat::\e[0m Assignment operator used for " << _type << std::endl;
	return (*this);
}

Cat::~Cat()
{
    std::cout << "\e[0;105mCat::\e[0m Destructor called for " << _type << std::endl;
    delete _brain;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string Cat::getType(void) const
{
    return _type;
}

//////////////////////////////////////////////////////////////////////////////////////

void Cat::makeSound(void) const
{
    std::cout << "\e[1;35mMiaaaaau miaau!\e[0m" << std::endl;
}

void Cat::addIdea(const std::string& idea)
{
    int i = 0;

    while (i < 100)
    {
        if (_brain->ideaIsEmpty(i))
        {
            _brain->addIdeaAtIndex(idea, i);
            return; 
        }
        i++;
    }
    if (i >= 100)
        std::cout << "Brain is full! Ignoring the new idea." << std::endl;
}

void Cat::printIdeas(void) const
{
    _brain->getIdeas();
}