#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float a, const float b) : _x(a), _y(b) {}

Point::~Point() {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &rhs)
{
    //not needed bc values are set during construct and shouldn't be modified since they're const
    // if (this != &rhs)
    // {
    //     (Fixed)this->_x = rhs._x;
    //     (Fixed)this->_y = rhs._y;
    // }
    return (*this);
}