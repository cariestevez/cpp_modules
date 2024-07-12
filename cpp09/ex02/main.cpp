#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sortMe(argc, argv);

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;

        sortMe.mergeInsertSort();

        // // // Sort using std::list
        // // std::list<int> numList(numbers.begin(), numbers.end());
        // // PmergeMe::mergeInsertSort(numList);

        // std::cout << "After: ";
        // sortMe.print();

        // std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << sortMe.getVecTime() << std::endl;
        // std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << sortMe.getLstTime() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}