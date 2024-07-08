#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (size_t i = 1; i < _size; i += 2)
    {
        // need to convert each arg(str into integer) and check it's valid. then saving the converted one into the pairs vector
        // if (!isdigit(*argv[i]) || *argv[i] < 0)
        //     throw (std::invalid_argument("Error: invalid input"));
        int convertedFirst = isValidInt(argv[i]);
        int convertedLast = isValidInt(argv[i + 1]);
        if (!convertedFirst || !convertedLast)
            throw (std::invalid_argument("Error: invalid input"));
        if (i + 1 < _size && convertedFirst > convertedLast)
        {
            _pairs.push_back(std::make_pair(convertedFirst, convertedLast));
        }
        else if (i + 1 < _size && convertedLast > convertedFirst)
        {
            _pairs.push_back(std::make_pair(convertedLast, convertedFirst));
        }
        else
        {
            _oddNum = convertedFirst;
        }
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
    _size = _unsorted.size();
}

PmergeMe::PmergeMe(const PmergeMe &source) : _oddNum(source._oddNum), _size(source._size), _unsorted(source._unsorted), _sorted(source._sorted), _insertionSequence(source._insertionSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this != &source)
    {
        _oddNum = source._oddNum;
        _size = source._size;
        _unsorted = source._unsorted;
        _sorted = source._sorted;
        _insertionSequence = source._insertionSequence;
    }
	
	return (*this);
}

PmergeMe::~PmergeMe() {}

//////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::mergeInsertSort()
{
    _insertionSequence = generateInsertionSequence();
}

void PmergeMe::print(void) const
{
    for (int i = 0; _sorted[i]; i++)
        std::cout << _sorted[i] << " ";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::generateInsertionSequence(void)
{
    std::vector<int> jacobsthalSequence = generateJacobsthalSequence();
    //int *jacobsthalSequence = generateJacobsthalSequence(argc, argv);

    //std::vector<int> insertionSequence;
    //int *insertionSequence = (int *)malloc(sizeof(int) * (argc - 1));

    _insertionSequence[0] = jacobsthalSequence[3];
    _insertionSequence[1] = jacobsthalSequence[3] - 1;

    int i = 1, j = 3;
    int last = jacobsthalSequence[3];

    //for ( ; ++j, ++i < argc - 1;)
    for ( ; ++j, ++i < _size;)
    {
        _insertionSequence[i] = jacobsthalSequence[j];
        int num = _insertionSequence[i];
        while (--num > last)
        {
            _insertionSequence[++i] = num;
        }
        last = jacobsthalSequence[j];
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(void)
{
    std::vector<int> jacobsthal(_size);
    // int *jacobsthal;
    // jacobsthal = (int *)malloc(sizeof(int) * (argc - 1));

    if (_size > 0) jacobsthal[0] = 0;
    if (_size > 1) jacobsthal[1] = 1;
    // if (argc - 1 > 0)
    // {
    //     jacobsthal[0] = 0;
    //     std::cout << "0: " << jacobsthal[0] << " ";
    // }
    // if (argc - 1 > 1)
    // {
    //     jacobsthal[1] = 1;
    //     std::cout << "1: " << jacobsthal[1] << " ";
    // }

    for (int i = 2; i < _size; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
    {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
    // for (int i = 2; i < argc; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
    // {
    //     jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    //     std::cout << i << ": " << jacobsthal[i] << " ";
    // }

    return jacobsthal;
}