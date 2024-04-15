#include <iostream>
#include <string>

//A reference is an alias or an alternative name for an existing object
//that allows you to access an object using a different name
//providing a convenient way to work with the same object without creating a copy.
//They must be initialized when declared
//Cannot be assigned to another object after declaration/definition. Reference to null isn't valid
//Don't occupy memory
//Used to pass args by reference, allowing to modify the original object, to avoid copying
int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of the str variable: " << &str         << std::endl;
    std::cout << "Memory address held by stringPTR: "   << stringPTR    << std::endl;
    std::cout << "Memory address held by stringREF: "   << &stringREF    << std::endl;
    
    std::cout << "Value of the string variable: "       << str          << std::endl;
    std::cout << "Value pointed to by stringPTR: "      << *stringPTR   << std::endl;
    std::cout << "Value pointed to by stringREF: "      << stringREF    << std::endl;

    return 0;
}