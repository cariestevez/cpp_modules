#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    int         intValue;
    float       floatValue;
    std::string stringValue;

    Data(int i, float f, const std::string& s) 
        : intValue(i), floatValue(f), stringValue(s) {}
};

#endif