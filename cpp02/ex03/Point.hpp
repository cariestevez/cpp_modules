#pragma one

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    ~Point();
    
    Point(const float a, const float b);
    Point(const Point &other);
    
    Point &operator=(const Point &other);

};
