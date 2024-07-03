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

	std::cout << "type: " << type << std::endl;
	
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
				std::cout << "e.what(): " << e.what() << std::endl;
			}
			break;
        
		case INT:
            try
			{
            	//int intValue = std::stoi(literal);
				std::istringstream iss(literal);
				int intValue;
				if (!(iss >> intValue) || !iss.eof())
				{
            		throw std::runtime_error("Invalid integer conversion");
				}
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
				std::cout << "e.what(): " << e.what() << std::endl;
			}
			break;
		
        case FLOAT:
            try
			{
				//float floatValue = std::stof(literal);
				std::istringstream iss(literal);
				float floatValue;
				if (!(iss >> floatValue) || !iss.eof())
				{
					throw std::invalid_argument("Invalid float conversion");
				}
				std::cout << std::fixed; // Set fixed-point notation
				std::cout << std::setprecision(1); // Set precision to 1 decimal place
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
				std::cout.unsetf(std::ios::fixed); // Reset cout flags
				std::cout.precision(6); // Reset precision to default
			}
			catch (const std::exception &e)
			{
				std::cout << "e.what(): " << e.what() << std::endl;
			}
			break;

        case DOUBLE:
            try
			{
                // double doubleValue = std::stod(literal);
				std::istringstream iss(literal);
				double doubleValue;
				if (!(iss >> doubleValue) || !iss.eof())
				{
					throw std::invalid_argument("Invalid double conversion");
				}
				std::cout << std::fixed; // Set fixed-point notation
				std::cout << std::setprecision(1); // Set precision to 1 decimal place
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
            	std::cout.unsetf(std::ios::fixed); // Reset cout flags
				std::cout.precision(6); // Reset precision to default
			}
			catch (const std::exception &e)
			{
				std::cout << "e.what(): " << e.what() << std::endl;
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
		return PSEUDOLITERAL;
	}

	else if (literal.length() == 1 && !isdigit(literal[0]))
	{
		return CHAR;
	}

    std::istringstream iss(literal);
    char nextChar;
    if (!(iss >> nextChar)) {
        return UNKNOWN;
    }

    if (nextChar == '-' || isdigit(nextChar)) {
        iss.putback(nextChar);

        // Check for presence of 'f'
        if (literal.find('f') != std::string::npos) {
            // Contains 'f' at the end, try as FLOAT
            float floatValue;
            if (iss >> floatValue && iss.eof()) {
                return FLOAT;
            }
        } else if (literal.find('.') != std::string::npos ||
                   literal.find('e') != std::string::npos ||
                   literal.find('E') != std::string::npos) {
            // Contains '.', 'e', or 'E', try as DOUBLE
            double doubleValue;
            if (iss >> doubleValue && iss.eof()) {
                return DOUBLE;
            }
        } else {
            // No '.', 'e', 'E', 'f', try as INT
            int intValue;
            if (iss >> intValue && iss.eof()) {
                return INT;
            }
        }
        // if (literal.find('.') != std::string::npos
		// 	|| literal.find('e') != std::string::npos
		// 	|| literal.find('E') != std::string::npos
		// 	|| literal.find('f') != std::string::npos)
		// {
        //     // Contains '.' or 'e'/'E', try float first
		// 	// double doubleValue;
		// 	double doubleValue;
		// 	float floatValue;
		// 	if (iss >> doubleValue && iss.eof())
		// 	{
        //         return DOUBLE;
        //     }
		// 	std::cout << "no double" << std::endl;
		// 	iss.clear();
        //     if (iss >> floatValue && literal.find('f') != std::string::npos)
		// 	{
        //         return FLOAT;
        //     }
        // }
		// else
		// {
        //     // No '.' or 'e'/'E', try integer
        //     int intValue;
        //     if (iss >> intValue && iss.eof())
		// 	{
        //         return INT;
        //     }
        // }
    }
    return UNKNOWN;
}

// LiteralType identifyLiteralType(std::string literal)
// {
// 	LiteralType type = UNKNOWN;
	
// 	if (literal == "nan" || literal == "+inf" || literal == "-inf"
// 		|| literal == "nanf" ||  literal == "+inff" || literal == "-inff")
// 	{
// 		return PSEUDOLITERAL;
// 	}

// 	else if (literal.length() == 1 && !isdigit(literal[0]))
// 	{
// 		return CHAR;
// 	}

// 	try
// 	{
// 		std::istringstream iss(literal);
// 		int intValue;
// 		if (!(iss >> intValue) || !iss.eof())
// 		{
// 			throw std::runtime_error("Invalid integer conversion");
// 		}
		
// 		return INT;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "e.what(): " << e.what() << std::endl;
// 	}

// 	if (type == UNKNOWN)
// 	{
// 		try
// 		{
// 			std::istringstream iss(literal);
// 			float floatValue;
// 			if (!(iss >> floatValue) || !iss.eof())
// 			{
// 				throw std::invalid_argument("Invalid float conversion");
// 			}
// 			// size_t pos;
// 			// float floatValue = std::stof(literal, &pos);
// 			// if (pos == literal.length() - 1 && literal[literal.length() - 1] == 'f')
// 			// {
// 			// 	return FLOAT;
// 			// }
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cout << "e.what(): " << e.what() << std::endl;
// 		}
// 		// catch (const std::invalid_argument &)
// 		// {
// 		// 	// Not a float, continue to next check
// 		// }
// 		// catch (const std::out_of_range &)
// 		// {
// 		// 	// Out of range for float, continue to next check
// 		// }

// 		try
// 		{
// 			std::istringstream iss(literal);
// 			double doubleValue;
// 			if (!(iss >> doubleValue) || !iss.eof())
// 			{
// 				throw std::invalid_argument("Invalid double conversion");
// 			}
// 			// size_t pos;
// 			// double doubleValue = std::stod(literal, &pos);
// 			// if (pos == literal.length())
// 			// {
// 			// 	return DOUBLE;
// 			// }
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cout << "e.what(): " << e.what() << std::endl;
// 		}
// 		// catch (const std::invalid_argument&)
// 		// {
// 		// 	// Not a double, continue
// 		// }
// 		// catch (const std::out_of_range&)
// 		// {
// 		// 	// Out of range for double, continue
// 		// }
// 	}

// 	return UNKNOWN;
// }