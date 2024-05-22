#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "\e[47mScalarConverter::\e[0m Default constructor called" << std::endl;  
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	std::cout << "\e[47mScalarConverter::\e[0m Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{

	std::cout << "\e[47mScalarConverter::\e[0m Assignment operator used" << std::endl;
	  
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "\e[47mScalarConverter::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const char* ScalarConverter::TypeConversionNotPossible::what() const throw()
{
    return "\e[47mScalarConverter::\e[0m \e[4;31mGrade too high!\e[0m";
}

//////////////////////////////////////////////////////////////////////////////////////

bool ScalarConverter::isChar(std::string str)
{
	return str.length() == 1 && std::isalpha(str[0]);
}

bool ScalarConverter::isInt(std::string str)
{
	errno = 0;
	char *p_end;

	long converted = std::strtol(str.c_str(), &p_end, 10);
	
	return *p_end == '\0' && errno == 0 && converted >= std::numeric_limits<int>::min() && converted <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(std::string str)
{
	errno = 0;
	char *p_end;
    
	float converted = std::strtof(str.c_str(), &p_end);
	
	return errno == 0 && converted != 0 && *p_end == *str.c_str()//??
	//return *p_end == 'f' && *(p_end + 1) == '\0';
}

bool ScalarConverter::isDouble(std::string str)
{
	return ((str.length() == 1) && std::isalpha(str[0])) 
}


//////////////////////////////////////////////////////////////////////////////////////

// If a conversion does not make any sense or overflows, display a message to inform
// the user that the type conversion is impossible.
static void convert(std::string str)
{
	//detect the type of the literal passed as parameter
	isChar(str)
	isInt(str)
	isFloat(str)
	isDouble(str)
	//convert it from string to its actual type

	//convert it explicitly to the three other data types

	//display the results as shown
}