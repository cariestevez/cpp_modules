#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "\e[0;101mBrain::\e[0m Default constructor called" << std::endl;

}

Brain::Brain(const Brain &source)
{
    for (int i = 0; i < 100; ++i) 
        _ideas[i] = source._ideas[i];//deep copy of ideas array

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

Brain::~Brain()//idea's array wasn't dynamically allocated, so no need to delete
{
    std::cout << "\e[0;101mBrain::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void Brain::getIdeas(void) const
{
    int i = 0;

    while (i < 100)
    {
        if (!ideaIsEmpty(i))
            std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
        i++;
    }
    if (i == 0)
        std::cout << "My brain is empty" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

bool Brain::ideaIsEmpty(int i) const
{
    return _ideas[i].empty();
}


void Brain::addIdeaAtIndex(const std::string& idea, int i)
{
    _ideas[i] = idea;
}

//////////////////////////////////////////////////////////////////////////////////////
