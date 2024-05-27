#include "iter.hpp"

void printInt(int x)
{
    std::cout << x << " ";
}

void printString(const std::string& str)
{
    std::cout << str << " ";
}

void incrementInt(int& x)
{
    ++x;
}

// Function template to print any type
template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementInt);

    std::cout << "Incremented int array: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    std::cout << "Int array with template print: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;


    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    std::size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArrayLength, printString);
    std::cout << std::endl;

    std::cout << "String array with template print: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}