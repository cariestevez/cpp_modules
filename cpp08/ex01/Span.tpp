#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

// Inserts a range of elements of any type of container
template <typename rangeIterator>
void Span::addRange(rangeIterator first, rangeIterator last)
{
    unsigned int spaceAvailable = _N - getSize();
    std::size_t rangeSize = std::distance(first, last);

    if (rangeSize > spaceAvailable)
        throw std::length_error("Could not add span because of unsificient space!");
    while (first != last)
    {
        addNumber(*first);
        first++;
    }
}

#endif