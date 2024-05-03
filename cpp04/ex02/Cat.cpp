#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _type("Cat")
{
    std::cout << "\e[0;105mCat::\e[0m Default constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type), _type(type)
{
    std::cout << "\e[0;105mCat::\e[0m Parameterized constructor called for " << _type << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &source) : Animal(source), _type(source._type)
{
    std::cout << "\e[0;105mCat::\e[0m Copy constructor called for " << _type << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
    if (this != &source)
    {
        Animal::operator=(source);
        _type = source._type;
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