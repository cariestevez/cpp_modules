#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack
{
private:
    std::stack<T, std::deque<T> > _dequeStack;
public:
    typedef typename std::deque<T>::iterator    iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
    
    MutantStack(void);
    MutantStack(unsigned int N);
    MutantStack(const MutantStack &source);
    MutantStack &operator=(const MutantStack &source);
    ~MutantStack(void);

    const std::deque<T> &getContainer(void);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;



    // push;
    // top;
    // size;
    // pop;
    // begin;
    // end;
};

#include "MutantStack.tpp"

#endif