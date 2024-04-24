#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _rawBits;
    static const int    _fractionalBits;
public:
    Fixed(void);
    Fixed(const int integer);
    Fixed(const float floating_point);
    Fixed(const Fixed &other);
    ~Fixed(void);
    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &instance);

#endif