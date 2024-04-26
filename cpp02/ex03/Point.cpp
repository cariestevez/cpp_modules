#include "Point.hpp"

//DEFAULT CONSTRUCTOR
Point::Point(void) : _x(0), _y(0) {}

//PARAMETERIZED CONSTRUCTOR
Point::Point(const float a, const float b) : _x(a), _y(b) {}

//DESTRCUTOR
Point::~Point() {}

//COPY CONSTRUCTOR
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

//COPY ASSIGNMENT OPERATOR
Point &Point::operator=(const Point &rhs)
{
    if (this != &rhs)
    {
        (Fixed)this->_x = rhs._x;
        (Fixed)this->_y = rhs._y;
    }
    return (*this);
}

//GETTERS
Fixed const Point::getX(void) const
{
    return _x;
}

Fixed const Point::getY(void) const
{
    return _y;
}