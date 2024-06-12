#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);

        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;

        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;

        std::srand(std::time(NULL));
        Span sp2 = Span(15000);

        for (int i = 0; i < 10000; i++)
        {
            int randomNum = std::rand() % std::numeric_limits<int>::max();
            sp2.addNumber(randomNum);
        }

        std::cout << "Span sp2 size: " << sp2.getSize() << std::endl;

        sp1.addSet(sp2.getContainer());
        
        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;
        
        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;

        std::vector<int> sp3;

        for (int i = 0; i < 20; i++)
        {
            int randomNum = std::rand() % std::numeric_limits<int>::max();
            sp3.push_back(randomNum);
        }
        
        std::cout << "Span sp3 size: " << sp3.size() << std::endl;

        sp2.addRange(sp3.begin(), sp3.end());

        std::cout << "Span sp1 size: " << sp1.getSize() << std::endl;

        std::cout << "Shortest Span in sp1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp1: " << sp1.longestSpan() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}