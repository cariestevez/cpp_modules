#include "Base.hpp"

// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base *generate(void)
{
    std::srand(std::time(0));//makes sure everytime there's a new value created

    int randomValue = std::rand();

    if (randomValue % 2)
        return new A;
    else if (randomValue % 3)
        return new B;
    else
        return new C;

}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
    if (dynamic_cast<A *>(p))//dynamic cast returns a nullptr if the cast is not possible
        std::cout << "A" << std::endl;
    
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    
    else
        std::cout << "Unknown type" << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.
void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast&)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast &)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast &)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

// Using dynamic_cast, you can safely identify the actual type of the object
// that a Base* pointer is pointing to.
// This is particularly useful in scenarios where you have a base class pointer
// that may point to any of several derived class objects.