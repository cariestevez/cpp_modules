// Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.

#include "Base.hpp"

int main()
{
    Base *p = generate();
    
    std::cout << "Identifying by pointer:" << std::endl;
    identify(p);
    
    std::cout << "Identifying by reference:" << std::endl;
    identify(*p);
    
    delete p;
    return 0;
}