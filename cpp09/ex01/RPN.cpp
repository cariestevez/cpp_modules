#include "RPN.hpp"

RPN::RPN(void)
{
    std::cout << "\e[0;103mRPN::\e[0m Default constructor called" << std::endl;
}

RPN::RPN(const RPN &source)
{
    std::cout << "\e[0;103mRPN::\e[0m Copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &source)
{
    if (this != &source)
        //code
	
    std::cout << "\e[0;103mRPN::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

RPN::~RPN()
{
    std::cout << "\e[0;103mRPN::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////
