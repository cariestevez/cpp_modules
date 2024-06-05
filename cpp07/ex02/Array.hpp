#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int n;
    public:
        Array(void);
        Array(unsigned int n);//amount of elements in the array
        Array(const Array &source);
        Array &operator=(const Array &source);
        ~Array(void);

}

#include "Array.tpp"

#endif