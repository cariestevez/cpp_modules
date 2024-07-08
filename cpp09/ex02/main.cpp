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
            std::cout << *argv[i] << " ";
        std::cout << std::endl;

        sortMe.mergeInsertSort();

        // // Sort using std::list
        // std::list<int> numList(numbers.begin(), numbers.end());
        // PmergeMe::mergeInsertSort(numList);

        std::cout << "After: ";
        sortMe.print();

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << sortMe.getVecTime() << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << sortMe.getLstTime() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}


// #include <iostream>
// #include <string>

// int *generateJacobsthalSequence(int argc, char **argv)
// {
//     int *jacobsthal;

//     jacobsthal = (int *)malloc(sizeof(int) * (argc - 1));

//     if (argc - 1 > 0)
//     {
//         jacobsthal[0] = 0;
//         std::cout << "0: " << jacobsthal[0] << " ";
//     }
//     if (argc - 1 > 1)
//     {
//         jacobsthal[1] = 1;
//         std::cout << "1: " << jacobsthal[1] << " ";
//     }

//     for (int i = 2; i < argc; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
//     {
//         jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
//         std::cout << i << ": " << jacobsthal[i] << " ";
//     }

//     std::cout << std::endl;

//     return jacobsthal;
// }

// int *generateInsertionSequence(int argc, char **argv)
// {
//     int *jacobsthalSequence = generateJacobsthalSequence(argc, argv);

//     int *insertionSequence = (int *)malloc(sizeof(int) * (argc - 1));

//     insertionSequence[0] = jacobsthalSequence[3];
//     insertionSequence[1] = jacobsthalSequence[3] - 1;

//     int i = 1, j = 3;
//     int last = jacobsthalSequence[3];
//     for ( ; ++j, ++i < argc - 1;)
//     {
//         insertionSequence[i] = jacobsthalSequence[j];
//         int num = insertionSequence[i];
//         while (--num > last)
//         {
//             insertionSequence[++i] = num;
//         }
//         last = jacobsthalSequence[j];

//     }

//     return insertionSequence;
// }


// int main(int argc, char **argv)
// {

//     int *insertionSeq = generateInsertionSequence(argc, argv);

//     std::cout << "printing insertion sequence: " << std::endl;
//     for (int i = 0; i < argc - 1; i++)
//         std::cout << insertionSeq[i] << " ";
    
//     std::cout << std::endl;
    
//     free(insertionSeq);
//     return 0;
// }