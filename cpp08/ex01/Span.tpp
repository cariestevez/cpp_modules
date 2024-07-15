#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::addContainer(const T &sourceContainer)
{
    addRange(sourceContainer.begin(), sourceContainer.end());
}

// Inserts a range of elements of any type of container
template <typename rangeIterator>
void Span::addRange(rangeIterator first, rangeIterator last)
{
    unsigned int spaceAvailable = _N - getSize();
    std::size_t rangeSize = std::distance(first, last);

    if (rangeSize > spaceAvailable)
        throw std::length_error("Could not add span because of unsuficient space!");
    
    _span.insert(first, last);

    std::cout << "Span added successfully" << std::endl;
}

#endif