#include "Fixed.hpp"

int main( void )
{
    Fixed a;//using default contructor
    Fixed b( a );//using copy constructor
    Fixed c;

    c = b;//Copy assignment operator called // <-- This line may be missing depending on your implementation
        //getRawBits member function called!! MISSING IN MY CODE
        //Default constructor called
        // Copy assignment operator called
        // getRawBits member function called!! MISSING IN MY CODE

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}