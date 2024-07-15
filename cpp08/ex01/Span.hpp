#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <exception>
#include <iterator>
#include <limits>

class Span
{
    private:
        std::string _name;
        unsigned int    _N;
        std::set<int>   _span;

    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &source);
        Span &operator=(const Span &source);
        ~Span(void);

        const std::set<int> &getContainer(void);
        unsigned int getSize(void) const;

        void addNumber(int number);
        template <typename T>
        void addContainer(const T &sourceContainer);
        template <typename rangeIterator>
        void addRange(rangeIterator first, rangeIterator last);
        int shortestSpan() const;
        int longestSpan() const;

        void checkSize() const;
};

#include "Span.tpp"

#endif