#include "PmergeMe.hpp"
#include "PmergeList.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe vecSequence(argc, argv);
        vecSequence.mergeInsertSort();
        // std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << sortMe.getVecTime() << std::endl;

        PmergeList listSequence(argc, argv);
        listSequence.mergeInsertSort();
        // std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << sortMe.getLstTime() << std::endl;
        
        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;
        std::cout << "After: ";
        vecSequence.print();
        listSequence.print();

        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}