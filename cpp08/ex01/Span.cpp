#include "Span.hpp"

Span::Span(void) : _N(10), _span()//initializes by default to 0
{
    std::cout << "\e[0;103mSpan::\e[0m Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N), _span()
{
    std::cout << "\e[0;103mSpan::\e[0m Parameterized constructor called" << std::endl;
}

Span::Span(const Span &source) :  _N(source._N), _span(source._span)//uses the copy constructor of the set container, which does a deep copy
{
    std::cout << "\e[0;103mSpan::\e[0m Copy constructor called " << std::endl;
}

Span &Span::operator=(const Span &source)
{
    if (this != &source)
    {
        _N = source._N;
        _span = source._span;
    }
    std::cout << "\e[0;103mSpan::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

Span::~Span()
{
    std::cout << "\e[0;103mSpan::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void Span::addNumber(int number)
{
    if (_span.size() < _N)
        _span.insert(number);
    //else
    // throw exception bc span is full
}

int Span::shortestSpan() const
{
    //if (_span.empty())
        //throw empty exception

}

int Span::longestSpan() const
{
    //if (_span.empty())
        //throw empty exception
    
}