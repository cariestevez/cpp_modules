#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iterator>

template <typename T>
MutantStack<T>::MutantStack(void) : _deque() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &source) : _deque(source._deque) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &source)
{
    if (this != &source)
    {
        _deque = source._deque;
    }
    
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

////////////////////////////////////////////////////////////////////

template <typename T>
T &MutantStack<T>::top(void)
{
    return _deque.back();
}

template <typename T>
void MutantStack<T>::pop(void)
{
    _deque.pop_back() ;
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
    _deque.push_back(value);
}

template <typename T>
size_t MutantStack<T>::size(void) const
{
    return _deque.size();
}

template <typename T>
bool MutantStack<T>::empty(void) const
{
    return _deque.empty();
}


////////////////////////////////////////////////////////////////////

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return getContainer().begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return getContainer().begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return getContainer().end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return getContainer().end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return getContainer().rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
    return getContainer().rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return getContainer().rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return getContainer().rend();
}

////////////////////////////////////////////////////////////////////

template<typename T>
std::deque<T> &MutantStack<T>::getContainer(void)
{
    return _deque;
}

#endif