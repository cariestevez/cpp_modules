#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(0));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << std::endl;
        std::cout << mirror[i] << std::endl;
    }

    Array<int> tmp = numbers;
    Array<int> test(tmp);

    try
    {
        numbers[4] = 9;
        mirror[4] = 5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // try
    // {
    //     numbers[MAX_VAL] = 70;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << std::endl;
        std::cout << mirror[i] << std::endl;
        std::cout << tmp[i] << std::endl;
        std::cout << test[i] << std::endl;
    }

    delete [] mirror;
 
    return 0;
}