#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <exception>

class Span
{
    private:
        unsigned int    _N;
        std::set<int>   _span;

    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &source);
        Span &operator=(const Span &source);
        ~Span(void);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif