#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &source);
        ScalarConverter &operator=(const ScalarConverter &source);
        ~ScalarConverter(void);
       
    public: 
        class TypeConversionNotPossible : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        bool isChar(std::string str);
        bool isInt(std::string str);
        bool isFloat(std::string str);
        bool isDouble(std::string str);

        static void convert(std::string literal);

};

#endif