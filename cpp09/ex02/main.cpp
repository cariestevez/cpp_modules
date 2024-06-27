#include "PmergeMe.hpp"

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    std::vector<int> unsortedVec;
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        int num;
        if (ss >> num && num >= 0)
        {
            unsortedVec.push_back(num);
        }
        else
        {
            std::cerr << "Error: Invalid input sequence." << std::endl;
            return 1;
        }
    }
    
    PmergeMe sortMe(unsortedVec);

    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < unsortedVec.size(); i++)
        std::cout << unsortedVec[i] << " ";
    std::cout << std::endl;

    sortMe.mergeInsertSort();

    // // Sort using std::list
    // std::list<int> numList(numbers.begin(), numbers.end());
    // PmergeMe::mergeInsertSort(numList);

    std::cout << "After: ";
    sortMe.print();

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << sortMe.getVecTime() << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << sortMe.getLstTime() << std::endl;

    return 0;
}
