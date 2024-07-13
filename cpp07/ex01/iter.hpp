#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F> 
void iter(T &array, std::size_t length, F function)
{
    for (std::size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif // ITER_HPP
