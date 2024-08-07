#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "\e[47mScalarConverter::\e[0m Default constructor called" << std::endl;  
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	(void)source;
	std::cout << "\e[47mScalarConverter::\e[0m Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{
	(void)source;
	std::cout << "\e[47mScalarConverter::\e[0m Assignment operator used" << std::endl;
	  
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "\e[47mScalarConverter::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

	//detect the type of the string literal passed as parameter
	//convert it from string to its actual type
	//convert it explicitly to the three other data types
	//display the results as shown

// Non displayable: if the char is a non printable
// Impossible: If a conversion does not make any sense or overflows
void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error! String is empty." << std::endl;
		return ;
	}
	
	LiteralType type = identifyLiteralType(literal);
	
	switch (type)
	{
        case CHAR:
			if (isprint(literal[0]))
				std::cout << "char: '" 	<< static_cast<char>(literal[0]) 	<< "'" 		<< std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			try
			{
				std::cout << "int: " 	<< static_cast<int>(literal[0]) 				<< std::endl;
				std::cout << "float: "	<< static_cast<float>(literal[0]) 	<< ".0f" 	<< std::endl;
				std::cout << "double: " << static_cast<double>(literal[0])	<< ".0"		<< std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "char exception: " << e.what() << std::endl;
			}
			break;
        
		case INT:
            try
			{
				char* endptr;
				const char* cstr = literal.c_str();
				long intValue = std::strtol(cstr, &endptr, 10);
		
				if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
				{
					if (isprint(intValue))
						std::cout << "char: '" 	<< static_cast<char>(intValue) 	<< "'" 	<< std::endl;
					else
						std::cout << "char: Non displayable" << std::endl;
				}
				else
					std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << intValue 										<< std::endl;
                std::cout << "float: " << static_cast<float>(intValue) 		<< ".0f" 	<< std::endl;
                std::cout << "double: " << static_cast<double>(intValue) 	<< ".0"		<< std::endl;
            }
			catch (const std::exception &e)
			{
				std::cout << "int exception: " << e.what() << std::endl;
			}
			break;
		
        case FLOAT:
            try
			{
				std::cout << std::fixed; // Set fixed-point notation
				std::cout << std::setprecision(1); // Set precision to 1 decimal place
				char *end;
				errno = 0;
				float floatValue = std::strtof(literal.c_str(), &end);
				
				if (errno == ERANGE)
				{
					throw std::out_of_range("Float out of range");
				}
				if (*end != 'f' || errno != 0)
				{
					throw std::invalid_argument("Invalid float conversion");
				}

				if (floatValue >= std::numeric_limits<char>::min() && floatValue <= std::numeric_limits<char>::max())
				{
					if (isprint(floatValue))
						std::cout << "char: '" 	<< static_cast<char>(floatValue) << "'" << std::endl;
					else
						std::cout << "char: Non displayable" << std::endl;
				}
				else
					std::cout << "char: impossible" << std::endl;
                std::cout << "int: " 	<< static_cast<int>(floatValue) 					<< std::endl;
                std::cout << "float: " 	<< floatValue 						<< "f" 			<< std::endl;
                std::cout << "double: " << static_cast<double>(floatValue) 					<< std::endl;
            }
			catch (const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			break;

        case DOUBLE:
            try
			{
				std::cout << std::fixed; // Set fixed-point notation
				std::cout << std::setprecision(1); // Set precision to 1 decimal place
				char *endptr;
				double doubleValue = std::strtod(literal.c_str(), &endptr);
				if (doubleValue >= std::numeric_limits<char>::min() && doubleValue <= std::numeric_limits<char>::max())
				{
					if (isprint(doubleValue))
						std::cout << "char: '" 	<< static_cast<char>(doubleValue) << "'" << std::endl;
					else
						std::cout << "char: Non displayable" << std::endl;
				}
				else
					std::cout << "char: impossible" << std::endl;
                std::cout << "int: " 		<< static_cast<int>(doubleValue) 			<< std::endl;
                std::cout << "float: " 		<< static_cast<float>(doubleValue) << "f" 	<< std::endl;
                std::cout << "double: " 	<< doubleValue 								<< std::endl;
            }
			catch (const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			break;

		case PSEUDOLITERAL:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" 	<< std::endl;
			if (literal == "nan" || literal == "+inf" || literal == "-inf" )
			{
				std::cout << "float: " 	<< literal << "f" 	<< std::endl;
				std::cout << "double: " << literal 			<< std::endl;
			}
			else
			{
				std::cout << "float: " 	<< literal 								<< std::endl;
				std::string copy = literal;
				std::cout << "double: " << copy.erase(literal.length() - 1) 	<< std::endl;
			}
			break;

        case UNKNOWN:
            std::cout << "Unknown literal type" << std::endl;
			break;
		
		default:
			break;
    }
}

LiteralType identifyLiteralType(const std::string &literal)
{
	LiteralType type = UNKNOWN;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf"
		|| literal == "nanf" ||  literal == "+inff" || literal == "-inff")
	{
		//std::cout << "Type: " << "PSEUDOLITERAL" << std::endl;
		return PSEUDOLITERAL;
	}

	else if (literal.length() == 1 && !isdigit(literal[0]))
	{
		//std::cout << "Type: " << "CHAR" << std::endl;
		return CHAR;
	}

	try
	{
		char* endptr;
		const char* cstr = literal.c_str();
		long value = std::strtol(cstr, &endptr, 10);
		if (!(*endptr != '\0' || endptr == cstr || value > INT_MAX || value < INT_MIN || errno != 0))
		{
			//std::cout << "Type: " << "INT" << std::endl;
			return INT;
			//;
			//throw std::runtime_error("Invalid integer conversion");
		}
		//else
	}
	catch (const std::exception &e)
	{
		std::cout << "identification exception 1: " << e.what() << std::endl;
	}

	if (type == UNKNOWN)
	{
		try
		{
			size_t pos;
			char *end;
			errno = 0;
			float floatValue = std::strtof(literal.c_str(), &end);

			if (*end == 'f' && literal[literal.length() - 1] == 'f' && errno == 0)
			{
				//std::cout << "Type: " << "FLOAT" << std::endl;
				return FLOAT;
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "identification exception 2: " << e.what() << std::endl;
		}

		try
		{
			char *endptr;
			errno = 0;
			double doubleValue = std::strtod(literal.c_str(), &endptr);

			if (endptr == literal.c_str() + literal.size())// Check if the entire string was converted
			{
				//std::cout << "Type: " << "DOUBLE" << std::endl;
				return DOUBLE;
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "identification exception 3: " << e.what() << std::endl;
		}
	}
	return UNKNOWN;
}