#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iterator>

template <typename T>
MutantStack<T>::MutantStack(void) : _dequeStack() {}

// template <typename T>
// MutantStack<T>::MutantStack(unsigned int n) : _dequeStack()
// {
    
// }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &source) : _dequeStack(source._dequeStack) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &source)
{
    if (this != &source)
    {
        _dequeStack = source._dequeStack;
    }
    
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

////////////////////////////////////////////////////////////////////

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return stack._Get_container().begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return stack._Get_container().begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return stack._Get_container().end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return stack._Get_container().end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return stack._Get_container().rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
    return stack._Get_container().rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return stack._Get_container().rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return stack._Get_container().rend();
}

////////////////////////////////////////////////////////////////////

const std::deque<T> &MutantStack<T>::getContainer(void)
{
    return _dequeStack.
}

// // Subscript operator (non-const version)
// //Allows modifying elements in the array
// template <typename T>
// T &MutantStack<T>::operator[](unsigned int index)
// {
//     if (index >= _n)
//         throw std::out_of_range("Index is out of range");
    
//     return _elements[index];
    
// }
// // Subscript operator (const version)
// //Allows read-only access to elements in the array
// template <typename T>
// const T &MutantStack<T>::operator[](unsigned int index) const
// {
//     if (index >= _n)
//         throw std::out_of_range("Index is out of range");
    
//     return _elements[index];
// }

// ////////////////////////////////////////////////////////////////////

// template <typename T>
// unsigned int MutantStack<T>::size(void) const
// {
//     return _n;
// }

#endif