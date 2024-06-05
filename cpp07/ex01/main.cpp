#include "iter.hpp"

void printInt(int x)
{
    std::cout << x << " ";
}

void printString(const std::string &str)
{
    std::cout << str << " ";
}

void incrementInt(int &x)
{
    x++;
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

    std::cout << "Print int array passing printInt function to iter: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    std::cout << "Incrementing int array... " << std::endl;
    iter(intArray, intArrayLength, incrementInt);

    std::cout << "Print int array passing printInt function to iter: ";
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    std::cout << "Print int array passing function template printElement to iter: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;


    std::string strArray[] = {"Amazing", "C++", "Templates"};
    std::size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Print string array passing printString function to iter: ";
    iter(strArray, strArrayLength, printString);
    std::cout << std::endl;

    std::cout << "Print string array passing function template printElement to iter: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}