#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _elements(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    _elements = new T[_n]();//parentheses initializes each single element of the array to 0
}

template <typename T>
Array<T>::Array(const Array &source) : _n(source._n)
{
    _elements = new T[_n];
    for (unsigned int i = 0; i < _n; ++i) 
        _elements[i] = source._elements[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &source)
{
    if (this != &source)
    {
        delete[] _elements;
        _n = source._n;
        _elements = new T[_n];
        for (unsigned int i = 0; i < _n; ++i)
        {
            _elements[i] = source._elements[i];
        }
    }
    
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] _elements;
}

////////////////////////////////////////////////////////////////////

// Subscript operator (non-const version)
//Allows modifying elements in the array
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw std::out_of_range("Index is out of range");
    
    return _elements[index];
    
}
// Subscript operator (const version)
//Allows read-only access to elements in the array
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index < 0 || index >= _n)
        throw std::out_of_range("Index is out of range");
    
    return _elements[index];
}

////////////////////////////////////////////////////////////////////

template <typename T>
unsigned int Array<T>::size(void) const
{
    return _n;
}

#endif