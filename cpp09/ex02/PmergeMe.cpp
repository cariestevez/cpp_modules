#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    _size = 0;
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
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &source) : _oddNum(source._oddNum), _size(source._size), _sorted(source._sorted), _insertionSequence(source._insertionSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this != &source)
    {
        _oddNum = source._oddNum;
        _size = source._size;
        // _unsorted = source._unsorted;
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

    if (endptr == numString || *endptr != '\0' || value > INT_MAX || value < INT_MIN)
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
    std::vector<int> insertion(_size);

    insertion[0] = jacobsthalSequence[3];
    insertion[1] = jacobsthalSequence[3] - 1;

    int i = 1, j = 3;
    int last = jacobsthalSequence[3];

    for ( ; ++j, ++i < _size;)
    {
        insertion[i] = jacobsthalSequence[j];
        int num = insertion[i];
        while (--num > last)
        {
            insertion[++i] = num;
        }
        last = jacobsthalSequence[j];
    }
    _insertionSequence = insertion;
    std::cout << "insertion: " << " ";
    for (int i = 0; i < _size; ++i)
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

    // std::cout << "jacobsthal: " << " ";
    for (int i = 2; i < _size + 2; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
    {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        // std::cout << jacobsthal[i] << " ";
    }
    // std::cout << std::endl;

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


void PmergeMe::merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::pair<int, int> > L(n1);
    std::vector<std::pair<int, int> > R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort on the pairs based on the first element
void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to sort pairs using merge sort
void PmergeMe::sortPairs()
{
    mergeSort(_pairs, 0, _pairs.size() - 1);

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

    std::cout << "main chain: " << " ";
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
    std::vector<int> sorted(_size);

    _sorted = sorted;
    size_t p = 0;
    size_t m = 0;
    size_t s = 0;
    size_t i = 0;
    while ((size_t)_insertionSequence[i] - 2 < _pend.size())
    {
        int key = _pend[_insertionSequence[i] - 2];
        if (key < _mainChain[m])
        {
            _sorted[s] = key;
            p++;
            std::cout << "case 1 - _sorted[" << s << "] = "
            << "_pend[" << _insertionSequence[i] - 2 << "] = " << key << std::endl;
            i++;
        }
        else
        {
            _sorted[s] = _mainChain[m];
            std::cout << "case 2 - _sorted[" << s << "] = "
            << "_mainChain[" << m << "] = " << _mainChain[m] << std::endl;
            m++;
        }
        s++;
    }

    if (p < _pend.size())
        _sorted[s++] = _pend[p++];

    while (m < _mainChain.size())
    {
        _sorted[s++] = _mainChain[m++];
    }
    // for (int i = 0, k = 0, s = 0; s < _size; s++)
    // {
    //     if (_pend[_insertionSequence[k] - 2] && _pend[_insertionSequence[k] - 2] < _mainChain[i])
    //     {
    //         _sorted[s] = _pend[_insertionSequence[k] - 2];
    //         std::cout << "case 1 - _sorted[" << s << "] = "
    //         << "_pend[" << _insertionSequence[k] - 2 << "] = " << _pend[_insertionSequence[k] - 2] << std::endl;
    //         k++;
    //     }
    //     else
    //     {
    //         _sorted[s] = _mainChain[i];
    //         std::cout << "case 2 - _sorted[" << s << "] = "
    //         << "_mainChain[" << i << "] = " << _mainChain[i] << std::endl;
    //         i++;
    //     }
    // }

    //need to add 
    _sorted[_size - 1] = _oddNum;
    std::cout << "SORTED: " << " ";
    for (unsigned long i = 0; i < _sorted.size(); ++i)
    {
        std::cout << _sorted[i] << " ";
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
