#include "whatever.hpp"

//COMPLEX CLASS FOR TEST
// class ComplexType
// {
//     public:
//         int value;
//         std::string name;

//         ComplexType(int v, std::string n) : value(v), name(n) {}

//         bool operator<(const ComplexType &other) const {
//             return value < other.value;
//         }

//         bool operator>(const ComplexType &other) const {
//             return value > other.value;
//         }

//         bool operator==(const ComplexType &other) const {
//             return value == other.value;
//         }
// };

// std::ostream &operator<<(std::ostream &os, const ComplexType &obj)
// {
//     os << "ComplexType(value: " << obj.value << ", name: " << obj.name << ")";
//     return os;
// }

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "string 3";
    std::string d = "string 2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    // //TESTING A COMPLEX CLASS
    // std::cout << std::endl;

    // ComplexType obj1(10, "First");
    // ComplexType obj2(20, "Second");

    // std::cout << "Before swap:\n";
    // std::cout << "obj1: " << obj1 << "\n";
    // std::cout << "obj2: " << obj2 << "\n";

    // swap(obj1, obj2);

    // std::cout << "\nAfter swap:\n";
    // std::cout << "obj1: " << obj1 << "\n";
    // std::cout << "obj2: " << obj2 << "\n";

    // std::cout << "\nMin of obj1 and obj2: " << min(obj1, obj2) << "\n";
    // std::cout << "Max of obj1 and obj2: " << max(obj1, obj2) << "\n";

    return 0;
}


