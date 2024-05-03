#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "\e[0;101mBrain::\e[0m Default constructor called" << std::endl;

}

// Brain::Brain(std::string type) : _type(type)
// {
//     std::cout << "\e[0;101mBrain::\e[0m Parameterized constructor called for " << _type << std::endl;
// }

Brain::Brain(const Brain &source)
{
    for (int i = 0; i < 100; ++i) 
        _ideas[i] = source._ideas[i];

    std::cout << "\e[0;101mBrain::\e[0m Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &source)
{
    std::cout << "\e[0;101mBrain::\e[0m Assignment operator called" << std::endl;

    if (this != &source)
    {
        for (int i = 0; i < 100; ++i) 
            _ideas[i] = source._ideas[i];
    }
    
    return (*this);
}

Brain::~Brain()
{
    std::cout << "\e[0;101mBrain::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
