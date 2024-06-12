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

const std::set<int> &Span::getContainer(void)
{
    return _span;
}

unsigned int Span::getSize(void) const
{
    return _span.size();
}

//////////////////////////////////////////////////////////////////////////////////////

void Span::addNumber(int number)
{
    if (getSize() < _N)
        _span.insert(number);
    else
        throw std::length_error("Could not add number because span is already full!");
}

void Span::addSet(const std::set<int> &sourceIntSpan)
{
    addRange(sourceIntSpan.begin(), sourceIntSpan.end());
}

void Span::addVector(const std::vector<int> &sourceIntSpan)
{
    addRange(sourceIntSpan.begin(), sourceIntSpan.end());
}

void Span::addList(const std::list<int> &sourceIntSpan)
{
    addRange(sourceIntSpan.begin(), sourceIntSpan.end());
}

//////////////////////////////////////////////////////////////////////////////////////

//smallest difference between any two consecutive numbers in the sorted set
int Span::shortestSpan() const
{
    checkSize();
    int distance = std::numeric_limits<int>::max();
    std::set<int>::const_iterator prev = _span.begin();
    std::set<int>::const_iterator next = prev;
    next++;
    for (; next != _span.end(); prev++, next++)
    {
        int result = *next - *prev;//compare each number only to the previous, since they're ordered
        if (result <= distance)
            distance = result;
    }
    return distance;
}

//maximum possible difference between any two numbers in that set
int Span::longestSpan() const
{
    checkSize();
    return *--_span.end() - *_span.begin();//end iterator points to the value after the last one!
}

void Span::checkSize() const
{
    if (getSize() <= 1)
        throw std::logic_error("Span has 1 or less numbers!");
}