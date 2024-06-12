#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <exception>

template <typename T>
typename T::const_iterator easyfind(T &paramA, int paramB)
{
    typename T::const_iterator    iter;

    for (iter = paramA.begin(); iter != paramA.end(); iter++)
    {
        if (*iter == paramB)
            return iter;
    }
    throw std::out_of_range("No ocurrence found");
}

#endif