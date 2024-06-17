#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iterator>

template <typename T>
MutantStack<T>::MutantStack(void) : _deque(), _dequeStack(_deque) {} //calling the constructor of the stack and passing it our deque

//whether deque = other.deque; performs a deep copy depends on the nature of the elements (T) stored in std::deque.
//For basic types ('int', 'double'...) or types with value semantics, it typically results in a shallow copy, where elements are copied by value.
//in case of std::string each std::string instance itself would perform a deep copy of its internal buffer
//if the elements themselves contained pointers or other objects managing their own memory (which is not the case)
//there would be a problem due to a shallow copy.
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &source) : _deque(source._deque), _dequeStack(_deque) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &source)
{
    if (this != &source)
    {
        _deque = source._deque;
        _dequeStack = std::stack<T, std::deque<T> >(_deque);//re-initializes stack calling the std::stack constructor passing it the new deque 
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

////////////////////////////////////////////////////////////////////

//to implement this functions, we can call the alredy existing functions of the stack container,
//which call the correspondent functions of the underlying container
// e.g. my top() function calls the stack.top() func and this one c.back() ('c' = deque)
// pop calls stack.pop() which calls c.pop_back() ('c' = deque)
template <typename T>
T &MutantStack<T>::top(void)
{
    return _dequeStack.top();
}

template <typename T>
void MutantStack<T>::pop(void)
{
    _dequeStack.pop() ;
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
    _dequeStack.push(value);
}

template <typename T>
size_t MutantStack<T>::size(void) const
{
    return _dequeStack.size();
}

template <typename T>
bool MutantStack<T>::empty(void) const
{
    return _dequeStack.empty();
}

////////////////////////////////////////////////////////////////////

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return _deque.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return _deque.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return _deque.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return _deque.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return _deque.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
    return _deque.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return _deque.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return _deque.rend();
}

////////////////////////////////////////////////////////////////////

template<typename T>
T &MutantStack<T>::operator*() const
{
    return *_dequeStack.top();
}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::operator++()
{
    ++_dequeStack;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::operator++(int)
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::operator--()
{
    --_dequeStack;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::operator--(int)
{
    iterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
bool MutantStack<T>::operator==(const iterator& other) const
{
    return _dequeStack.top() == other._dequeStack.top();
}

template<typename T>
bool MutantStack<T>::operator!=(const iterator& other) const
{
    
    return !(*this == other);
    //return _dequeStack != other._dequeStack;
}

#endif