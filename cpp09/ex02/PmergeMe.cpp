#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    _size = 0;
    _oddNum = -1;
    for (int i = 1; i < argc; i += 2)
    {
        // need to convert each arg(str into integer) and check it's valid. then saving the converted one into the pairs vector
        int convertedFirst = convertToInt(argv[i]);
        std::cout << "tried to convert argv[" << i << "] = " << convertedFirst << std::endl;
        int convertedLast = convertToInt(argv[i + 1]);
        std::cout << "and argv[" << i + 1 << "] = " << convertedLast << std::endl;
        if (convertedFirst < 0 || convertedLast == -2)
            throw (std::invalid_argument("Error: invalid input"));
        if (convertedLast < 0)
        {
            _oddNum = convertedFirst;
            _size += 1;
        }
        else if (convertedFirst > convertedLast)
        {
            _pairs.push_back(std::make_pair(convertedFirst, convertedLast));
            _size += 2;
        }
        else //(convertedLast > convertedFirst)
        {
            _pairs.push_back(std::make_pair(convertedLast, convertedFirst));
            _size += 2;
        }
        std::cout << "size: " << _size << std::endl;
    }
    std::cout << "pairs: " << " ";
    for (unsigned long i = 0; i < _pairs.size(); ++i)
    {
        std::cout << _pairs[i].first << " " << _pairs[i].second <<  " - ";
    }
    std::cout << "_oddNum: " << _oddNum;
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &source) : _oddNum(source._oddNum), _size(source._size), _sorted(source._sorted), _insertionSequence(source._insertionSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this != &source)
    {
        _oddNum = source._oddNum;
        _size = source._size;
        _sorted = source._sorted;
        _insertionSequence = source._insertionSequence;
    }
	
	return (*this);
}

PmergeMe::~PmergeMe() {}

//////////////////////////////////////////////////////////////////////////////////////

int PmergeMe::convertToInt(char *numString)
{
    if (!numString)
        return -1;

    char *endptr;
    long value = std::strtol(numString, &endptr, 10);

    if (endptr == numString || *endptr != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        return -2;

    return static_cast<int>(value);
}

void PmergeMe::print(void) const
{
    for (int i = 0; _sorted[i]; i++)
        std::cout << _sorted[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::generateInsertionSequence(void)
{
    std::vector<int> jacobsthalSequence = generateJacobsthalSequence();
    std::vector<int> insertion(_pend.size() - 1);

    insertion[0] = jacobsthalSequence[3];
    if (_pend.size() > 1)
        insertion[1] = jacobsthalSequence[3] - 1;

    if (_pend.size() > 2)
    {
        size_t i = 1, j = 3;
        int last = jacobsthalSequence[3];

        for ( ; ++j, ++i < _pend.size();)
        {
            insertion[i] = jacobsthalSequence[j];
            int num = insertion[i];
            while (--num > last)
            {
                insertion[++i] = num;
            }
            last = jacobsthalSequence[j];
        }
    }
    _insertionSequence = insertion;
    std::cout << "insertion: " << " ";
    for (size_t i = 0; i < _insertionSequence.size(); ++i)
    {
        std::cout << _insertionSequence[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(void)
{
    std::vector<int> jacobsthal(_size);

    if (_size > 0) jacobsthal[0] = 0;
    if (_size > 1) jacobsthal[1] = 1;

    for (int i = 2; i < _size + 2; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
    {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }

    return jacobsthal;
}

// void PmergeMe::sortPairs(void)//change for the merge sort algorithm!
// {
//     for (unsigned long i = 0; i < _pairs.size() - 1; i++)
//     {
//         if (_pairs[i].first > _pairs[i + 1].first)
//         {
//             std::pair<int, int> temp = _pairs[i];
//             _pairs[i] = _pairs[i + 1];
//             _pairs[i + 1] = temp;
//         }
        
//     }

//     std::cout << "sorted pairs: " << " ";
//     for (unsigned long i = 0; i < _pairs.size(); ++i)
//     {
//         std::cout << _pairs[i].first << " " << _pairs[i].second <<  " - ";
//     }
//     std::cout << std::endl;
// }


// void PmergeMe::merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     std::vector<std::pair<int, int> > L(n1);
//     std::vector<std::pair<int, int> > R(n2);

//     for (int i = 0; i < n1; ++i)
//         L[i] = arr[left + i];
//     for (int i = 0; i < n2; ++i)
//         R[i] = arr[mid + 1 + i];

//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i].first <= R[j].first) {
//             arr[k] = L[i];
//             ++i;
//         } else {
//             arr[k] = R[j];
//             ++j;
//         }
//         ++k;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         ++i;
//         ++k;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         ++j;
//         ++k;
//     }
// }

// //Function to perform merge sort on the pairs based on the first element
// void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right)
// {
//     if (left < right) {
//         int mid = left + (right - left) / 2;

//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         merge(arr, left, mid, right);
//     }
// }

// Function to sort pairs using merge sort
void PmergeMe::sortPairs()
{
    //mergeSort(_pairs, 0, _pairs.size() - 1);

    std::sort(_pairs.begin(), _pairs.end());
    std::cout << "sorted pairs: ";
    for (unsigned long i = 0; i < _pairs.size(); ++i) {
        std::cout << "(" << _pairs[i].first << ", " << _pairs[i].second << ") ";
    }
    std::cout << std::endl;
}


void PmergeMe::divideChains()
{
    std::vector<int> mainChain(_pairs.size() + 1);
    std::vector<int> pend(_pairs.size() - 1);

    _mainChain = mainChain;
    _pend = pend;
    _mainChain[0] = _pairs[0].second;

    for (unsigned long i = 1; i <= _pairs.size(); ++i)
    {
        _mainChain[i] = _pairs[i - 1].first;
        _pend[i - 1] = _pairs[i].second;
    }

    std::cout << "_mainChain: " << " ";
    for (unsigned long i = 0; i < _mainChain.size(); ++i)
    {
        std::cout << _mainChain[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "_pend: " << " ";
    for (unsigned long i = 0; i < _pend.size(); ++i)
    {
        std::cout << _pend[i] << " ";
    }
    std::cout << std::endl;

}


void PmergeMe::insertSort()
{
    std::vector<int>::iterator it;
    int key = 0;

    for (size_t i = 0, j = 0; j < _pend.size(); i++)
    {
        if (i < _insertionSequence.size())
            key = _pend[_insertionSequence[i] - 2];
        else
            key = *(_pend.end() - 1);
        std::cout << "key: " << key << std::endl;

        it = _mainChain.begin();
        while (it != _mainChain.end() && key > *it)
        {
            std::cout << "incrementing mainChain ptr" << std::endl;
            it++;
        }
        _mainChain.insert(it, key);
        j++;
        std::cout << "inserted " << key << std::endl;

    }
    if (_oddNum >= 0)
    {
        std::cout << "ODD " << _oddNum << std::endl;
        std::vector<int>::iterator it = _mainChain.begin();
        while (it != _mainChain.end() && _oddNum > *it)
        {
            std::cout << "incrementing mainChain ptr for ODD" << std::endl;
            it++;
        }
        _mainChain.insert(it, _oddNum);
    }
    std::cout << "SORTED: " << " ";
    for (unsigned long i = 0; i < _mainChain.size(); ++i)
    {
        std::cout << _mainChain[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSort()
{
    sortPairs();
    divideChains();
    generateInsertionSequence();
    insertSort();
}
