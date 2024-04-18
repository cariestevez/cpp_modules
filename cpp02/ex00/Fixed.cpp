#include "Fixed.hpp"

//static declaration, shared by every instance of the class
const int   Fixed::_fractionalBits = 8;

//default constructor
Fixed::Fixed(void) : _fixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed &other) : _fixedPointNum(other._fixedPointNum)
{
    std::cout << "Copy constructor called" << std::endl;
}

//copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Avoid self-assignment
        _fixedPointNum = other._fixedPointNum;
    }
    return (*this);
}

//destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;

}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointNum);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointNum = raw;

}