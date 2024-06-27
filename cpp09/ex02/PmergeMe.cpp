#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> &userInput)
{
    _unsorted = userInput;
}

PmergeMe::PmergeMe(const PmergeMe &source) : _oddNum(source._oddNum), _unsorted(source._unsorted), _sorted(source._sorted), _insertionSequence(source._insertionSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this != &source)
    {
        _oddNum = source._oddNum;
        _unsorted = source._unsorted;
        _sorted = source._sorted;
        _insertionSequence = source._insertionSequence;
    }
	
	return (*this);
}

PmergeMe::~PmergeMe() {}

//////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::print(void) const
{
    for (int i = 0; _sorted[i]; i++)
        std::cout << _sorted[i] << " ";
    std::cout << std::endl;
}

std::vector<int> generateInsertionSequence(int n)
{
    std::vector<int> jacobsthalSequence = generateJacobsthalSequence(n);

    std::vector<int> insertionSequence;

    insertionSequence[0] = jacobsthalSequence[3];
    int lastJacobsNum = jacobsthalSequence[3];
    for (int i = 1, j = 3; i < n; i++)
    {
        if (insertionSequence[i - 1] == jacobsthalSequence[j] && j != 3)
        {
            while()
            insertionSequence[i] = 
        }
        else
            insertionSequence[i] = jacobsthalSequence[3]
    }
}

std::vector<int> generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal(n);

    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;

    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }

    return jacobsthal;
}