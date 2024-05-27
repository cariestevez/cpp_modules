#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

//The following funcs are templates, and must be instanciated (in main) 
// These functions can be called with any type of argument. The only requirement is
// that the two arguments must have the same type and must support all the comparison
// operators. This is done by the typename args

// • swap: Swaps the values of two given arguments. Does not return anything.
template <typename T> // == template <typename T, typename T'>' -> both args of same type
void swap(T &a, T &b) 
{
   T temp = a;
   a = b;
   b = temp;
}

// • min: Compares the two values passed in its arguments and returns the smallest
// one. If the two of them are equal, then it returns the second one.
template <typename T>
const T &min(T const &a, T const &b)
{
    return ( a < b ? a : b );
}

// • max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T &max(T const &a, T const &b)
{
    return ( a > b ? a : b );
}

#endif // WHATEVER_HPP