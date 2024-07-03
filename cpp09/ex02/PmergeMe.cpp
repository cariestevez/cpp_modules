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
    insertionSequence[1] = jacobsthalSequence[3] - 1;

    int i = 1, j = 3;

    for ( ; ++i < n;)
    {
        int last = j;
        int num = jacobsthalSequence[last - 1];
        j++;
        while (num > jacobsthalSequence[last])
        {
            insertionSequence[i] = num;
            i++;
            num--;
        }

    }
}

std::vector<int> generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal(n);

    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;

    for (int i = 2; i < n + 2; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
    {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }

    return jacobsthal;
}