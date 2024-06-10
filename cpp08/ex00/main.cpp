#include "easyfind.hpp"

int main()
{
    try
    {
        std::list<int>  lst;
        lst.push_back(5);
        lst.push_back(7);
        lst.push_back(9);
        std::cout << "List: " << *easyfind(lst, 7) << std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        std::cout << "Vector: " << *easyfind(vec, 3) << std::endl;

        std::cout << "Vector: " << *easyfind(vec, 14) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}