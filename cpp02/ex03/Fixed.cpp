#include "Fixed.hpp"

const int   Fixed::_fractionalBits = 8;

//----------------------------------------------------------------------------------------------------------//

Fixed::Fixed(void) : _rawBits(0)
{
   // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
   // std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
   // std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}
// Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
// {
//     std::cout << "Copy constructor called" << std::endl;
// }

// Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
  //  std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return (*this);
}
// Fixed &Fixed::operator=(const Fixed &other)
// {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &other) { // Avoid self-assignment
//         _rawBits = other._rawBits;
//     }
//     return (*this);
// }

//----------------------------------------------------------------------------------------------------------//

int Fixed::getRawBits(void) const
{
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

//----------------------------------------------------------------------------------------------------------//

// Int constructor
// shift the bits by _fractionalBits to the left( = x2^8, being 8 the fractional bits),
// to reserve _fractionalBits bits for the fractional part of the number to be represented. 1 would be/start at 256
Fixed::Fixed(const int integer)
{
   // std::cout << "Int constructor called" << std::endl;
    this->_rawBits = integer << _fractionalBits;
}

// Floating point constructor
// convert 1(int) to fixed point(= reserve last 8 bits in this case) => 256,
// now multiply this by the fractional number
Fixed::Fixed(const float floating_point)
{
  //  std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(floating_point * (1 << _fractionalBits));
}

//----------------------------------------------------------------------------------------------------------//

//divides by 256(= 2^8) to go back to the floating value
float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (float)(1 << _fractionalBits));
}

//shifts the bits back to the right, since the reserved bits are empty
int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &output, Fixed const &instance)
{
    //output << instance.getRawBits(); //outputs binary result
    output << instance.toFloat();
    return output;
}

//----------------------------------------------------------------------------------------------------------//

bool    Fixed::operator>(const Fixed &rhs) const
{
    if (_rawBits > rhs._rawBits)
        return true;
    else
        return false;
}
// bool	Fixed::operator>( const Fixed &rhs ) const
// {
// 	return this->getRawBits() > rhs.getRawBits();
// }

bool    Fixed::operator<(const Fixed &rhs) const
{
    if (_rawBits < rhs._rawBits)
        return true;
    else
        return false;
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    if (_rawBits >= rhs._rawBits)
        return true;
    else
        return false;
}

bool    Fixed::operator<=(const Fixed &rhs) const
{
    if (_rawBits <= rhs._rawBits)
        return true;
    else
        return false;
}

bool    Fixed::operator==(const Fixed &rhs) const
{
    if (_rawBits == rhs._rawBits)
        return true;
    else
        return false;
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    if (_rawBits != rhs._rawBits)
        return true;
    else
        return false;
}

//----------------------------------------------------------------------------------------------------------//

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed copy(*this);
    copy = this->toFloat() + rhs.toFloat();
    return copy;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed copy(*this);
    copy = this->toFloat() - rhs.toFloat();
    return copy;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed copy(*this);
    copy = this->toFloat() * rhs.toFloat();
    return copy;
    //return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed copy(*this);
    copy = this->toFloat() / rhs.toFloat();
    return copy;
}

//----------------------------------------------------------------------------------------------------------//

Fixed &Fixed::operator++()
{
    _rawBits += 1;
    return *this;
}

Fixed &Fixed::operator--()
{
    _rawBits -= 1;
    return *this;
}

// marker to distinguish between the two operator overloads pre and post
// doesn't serve any functional purpose
Fixed Fixed::operator++(int dummyMarker)
{
    (void)dummyMarker;
    Fixed copy(*this);//creating copy of the instance for returning
    ++(*this);//increment the original instance's var using the pre increment func created before
    return copy;//return copy with the old value of the var inside before incrementing
}

Fixed Fixed::operator--(int dummyMarker)
{
    (void)dummyMarker;
    Fixed copy(*this);
    --(*this);
    return copy;
}

//----------------------------------------------------------------------------------------------------------//

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a._rawBits < b._rawBits)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a._rawBits < b._rawBits)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a._rawBits > b._rawBits)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a._rawBits > b._rawBits)
        return a;
    else
        return b;
}