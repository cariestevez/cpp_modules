#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    std::cout << "\e[0;103mPmergeMe::\e[0m Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &source)
{
    std::cout << "\e[0;103mPmergeMe::\e[0m Copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this != &source)
        //code
	
    std::cout << "\e[0;103mPmergeMe::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe()
{
    std::cout << "\e[0;103mPmergeMe::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::print(void) const
{
    for (int i = 0; _unsorted[i]; i++)
        std::cout << "Before: " << _unsorted[i] << " ";
    std::cout << std::endl;
    
    for (int i = 0; _sorted[i]; i++)
        std::cout << "After: " << _sorted[i] << " ";
    std::cout << std::endl;

}