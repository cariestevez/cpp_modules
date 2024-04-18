#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int                 _fixedPointNum;
    static const int    _fractionalBits;
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};




#endif