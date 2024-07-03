#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, PSEUDOLITERAL, UNKNOWN };

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &source);
        ScalarConverter &operator=(const ScalarConverter &source);
        ~ScalarConverter(void);
       
    public: 
        static void convert(const std::string &literal);
};

LiteralType identifyLiteralType(const std::string &literal);

#endif