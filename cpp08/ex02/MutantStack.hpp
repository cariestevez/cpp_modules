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
        std::deque<T> _deque;

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

        std::deque<T> &getContainer(void);

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        T &top(void);
        void pop(void);
        void push(const T &value);
        size_t size(void) const;
        bool empty(void) const;

};

#include "MutantStack.tpp"

#endif