#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error! Usage: <executableName> <stringLiteral>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]); // Corrected call
    
    return 0;
}
