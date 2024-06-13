#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        Span sp1 = Span(30000);
        //Testing shortest and longest span on empty set
        // std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        // std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;
        sp1.addNumber(6);
        //Testing shortest and longest span with only one value in set
        // std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        // std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;
        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;

        std::srand(std::time(NULL));
        //Testing adding sp2 to sp1 when sp2 too big for remaining space in sp1
        // Span sp2 = Span(40000);
        // for (int i = 0; i < 40000; i++)
        // {
        //     int randomNum = std::rand() % std::numeric_limits<int>::max();
        //     sp2.addNumber(randomNum);
        // }
        //Testing addSet function
        Span sp2 = Span(28000);
        for (int i = 0; i < 28000; i++)
        {
            int randomNum = std::rand() % std::numeric_limits<int>::max();
            sp2.addNumber(randomNum);
        }
        std::cout << "Span sp2 size: " << sp2.getSize() << std::endl;
        sp1.addSet(sp2.getContainer());  
        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;  
        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;

        //Testing adding a vector to the set sp1 with addRange function
        std::vector<int> vec;
        for (int i = 0; i < 100; i++)
        {
            int randomNum = std::rand() % std::numeric_limits<int>::max();
            vec.push_back(randomNum);
        } 
        std::cout << "Span vector size: " << vec.size() << std::endl;
        sp1.addRange(vec.begin(), vec.end());
        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;
        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;

        //Testing adding a list to the set sp1 with addNumber and addRange functions
        std::list<int> lst;
        lst.push_back(30);
        sp1.addNumber(*lst.begin());
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Span list size: " << lst.size() << std::endl;
        sp1.addRange(++lst.begin(), lst.end());
        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;
        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\e[1;91mException caught: " << e.what() << "\e[0m" << std::endl;
    }
    
    return 0;
}