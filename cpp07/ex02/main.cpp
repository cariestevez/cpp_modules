#include "Array.hpp"
#define MAX_VAL 3

//COMPLEX CLASS FOR TEST
// class Complex
// {
//     public:
//         Complex() : a(0), b(0) {}
//         Complex(int a, int b) : a(a), b(b) {}

//         int getA() const { return a; }
//         int getB() const { return b; }

//     private:
//         int a, b;
// };

// std::ostream &operator<<(std::ostream &os, const Complex &c)
// {
//     os << "(" << c.getA() << ", " << c.getB() << ")";
//     return os;
// }

int main(int, char**)
{
    int *mirror = new int[MAX_VAL];
    
    try
    {
        Array<int> empty;

        Array<int> originalTemplate(MAX_VAL);
        
        srand(time(0));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            originalTemplate[i] = value;
            mirror[i] = value;
        }
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << "originalTemplate[" << i << "] " << originalTemplate[i] << std::endl;
            std::cout << "mirror[" << i << "] " << mirror[i] << std::endl;
        }

        Array<int> assigned = originalTemplate;
        Array<int> copy(originalTemplate);
        originalTemplate[2] = 9;
        mirror[2] = 5;
        std::cout << "originalTemplate[OUTOFBOUND] " << originalTemplate[100] << std::endl;
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << "originalTemplate[" << i << "] " << originalTemplate[i] << std::endl;
            std::cout << "mirror[" << i << "] " << mirror[i] << std::endl;
            std::cout << "assigned[" << i << "] " << assigned[i] << std::endl;
            std::cout << "copy[" << i << "] " << copy[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    //TESTING WITH A COMPLEX CLASS
    // try
    // {
    //     Array<Complex> complexArray(3);
    //     complexArray[0] = Complex(1, 2);
    //     complexArray[1] = Complex(3, 4);
    //     complexArray[2] = Complex(5, 6);
    //     for (unsigned int i = 0; i < complexArray.size(); ++i)
    //     {
    //         std::cout << complexArray[i] << std::endl;
    //     }
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    delete [] mirror;

    return 0;
}