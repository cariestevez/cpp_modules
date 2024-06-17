#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iterator>

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T, std::deque<T> >() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &source) : std::stack<T, std::deque<T> >(source) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &source)
{
    if (this != &source)
    {
        std::stack<T, std::deque<T> >::operator=(source);//calls the assignment operator of the stack instance
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

////////////////////////////////////////////////////////////////////

//accessing the underlying container (deque by default) iterator functions through c(container) private attribute in the stack
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
    return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return this->c.rend();
}

#endif