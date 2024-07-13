#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T &paramA, int paramB)
{
    typename T::const_iterator iter = std::find(paramA.begin(), paramA.end(), paramB);
    
    if (iter != paramA.end())
        return iter;
    else
        throw std::out_of_range("No ocurrence found");

}

#endif