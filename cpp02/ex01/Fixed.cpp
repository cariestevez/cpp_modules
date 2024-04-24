#include "Fixed.hpp"

//static declaration, shared by every instance of the class
const int   Fixed::_fractionalBits = 8;

//default constructor
Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

//Int constructor
Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = integer << _fractionalBits;
}

//Floating point constructor
Fixed::Fixed(const float floating_point)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(floating_point * (1 << _fractionalBits));
}

//copy constructor
// Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
// {
//     std::cout << "Copy constructor called" << std::endl;
// }
// same as:
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

//copy assignment operator overload
// Fixed &Fixed::operator=(const Fixed &other)
// {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &other) { // Avoid self-assignment
//         _rawBits = other._rawBits;
//     }
//     return (*this);
// }
//same as:
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return (*this);
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &output, Fixed const &instance)
{
    output << instance.toFloat();
    //output << instance.getRawBits(); //for binary
    return output;
}