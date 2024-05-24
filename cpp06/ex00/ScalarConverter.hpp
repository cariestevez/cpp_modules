#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <iomanip>

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, PSEUDOLITERAL, UNKNOWN };

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &source);
        ScalarConverter &operator=(const ScalarConverter &source);
        ~ScalarConverter(void);
       
    public: 
        static void convert(std::string literal);
};

LiteralType identifyLiteralType(std::string literal);

#endif