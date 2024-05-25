#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer &source);
        Serializer &operator=(const Serializer &source);
        ~Serializer(void);
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

// Pointer manipulation: How to convert pointers to integral types and back.
// Type casting: Using reinterpret_cast for type conversions.
// Platform independence: Using uintptr_t to ensure pointers can be stored as integers.
// Static utility classes: Creating non-instantiable classes with static methods.
// Safe type conversions: Ensuring conversions are accurate and do not lead to data corruption.