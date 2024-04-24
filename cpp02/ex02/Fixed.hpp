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
    ~Fixed(void);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    Fixed(const int integer);
    Fixed(const float floating_point);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;

    bool    operator>(const Fixed &rhs) const;
    bool    operator<(const Fixed &rhs) const ;
    bool    operator>=(const Fixed &rhs) const ;
    bool    operator<=(const Fixed &rhs) const ;
    bool    operator==(const Fixed &rhs) const ;
    bool    operator!=(const Fixed &rhs) const ;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int old);
    Fixed operator--(int old);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &instance);

#endif