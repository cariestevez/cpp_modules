#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *_elements;
        unsigned int _n;
    public:
        Array(void);
        Array(unsigned int n);//amount of elements in the array
        Array(const Array &source);
        Array &operator=(const Array &source);
        ~Array(void);

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        unsigned int size(void) const;
};

#include "Array.tpp"

#endif