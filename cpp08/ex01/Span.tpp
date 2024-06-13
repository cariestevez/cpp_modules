#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

// Inserts a range of elements of any type of container
template <typename rangeIterator>
void Span::addRange(rangeIterator first, rangeIterator last)
{
    unsigned int spaceAvailable = _N - getSize();
    std::size_t rangeSize = std::distance(first, last);

    // std::cout << _name << "-> _N: " << _N << "\nSize: " << getSize() << "\n=> Available space: " << spaceAvailable << "\nRange size to add: " << rangeSize << std::endl;

    if (rangeSize > spaceAvailable)
        throw std::length_error("Could not add span because of unsuficient space!");
    while (first != last)
    {
        addNumber(*first);
        first++;
    }
    std::cout << "Span added successfully" << std::endl;
}

#endif