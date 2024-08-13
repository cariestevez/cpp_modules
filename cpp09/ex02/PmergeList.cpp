#include "PmergeList.hpp"

PmergeList::PmergeList(int argc, char **argv)
{
    _startTime = clock();
    _size = 0;
    _oddNum = -1;

    for (int i = 1; i < argc; i += 2)
    {
        int convertedFirst = convertToInt(argv[i]);
        int convertedLast = (i + 1 < argc) ? convertToInt(argv[i + 1]) : -1;

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
    }
    // //debug print
    // std::cout << "pairs: " << " ";
    // for (std::list<std::pair<int, int> >::const_iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << " - ";
    // }
    // std::cout << "_oddNum: " << _oddNum;
    // std::cout << std::endl;
}

PmergeList::PmergeList(const PmergeList &source) : _oddNum(source._oddNum), _size(source._size), _insertionSequence(source._insertionSequence) {}

PmergeList &PmergeList::operator=(const PmergeList &source)
{
    if (this != &source)
    {
        _oddNum = source._oddNum;
        _size = source._size;
        _insertionSequence = source._insertionSequence;
    }
	
	return (*this);
}

PmergeList::~PmergeList() {}

//////////////////////////////////////////////////////////////////////////////////////

int PmergeList::convertToInt(char *numString)
{
    if (!numString)
        return -1;

    char *endptr;
    long value = std::strtol(numString, &endptr, 10);

    if (endptr == numString || *endptr != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        return -2;

    return static_cast<int>(value);
}

void PmergeList::print(void) const
{
    std::cout << "Sorted list: ";
    for (std::list<int>::const_iterator it = _mainChain.begin(); it != _mainChain.end(); ++it)
    {
        std::cout << *it << "-";
    }

    std::cout << std::endl;
}

void PmergeList::generateInsertionSequence(void)
{
    std::list<int> jacobsthalSequence = generateJacobsthalSequence();
    std::list<int> insertion;

    if (!_pend.empty())
    {
        std::list<int>::iterator jacobIt = jacobsthalSequence.begin();
        std::advance(jacobIt, 3);  // Move to the 4th element (index 3)

        insertion.push_back(*jacobIt);

        if (_pend.size() > 1)
            insertion.push_back(*jacobIt - 1);

        if (_pend.size() > 2)
        {
            size_t i = 1;
            int last = *jacobIt;
            std::list<int>::iterator pendIt = _pend.begin();

            std::advance(pendIt, 2);  // Start from the 3rd element of _pend

            while (++i < _pend.size() && ++jacobIt != jacobsthalSequence.end())
            {
                insertion.push_back(*jacobIt);

                int num = *jacobIt;
                while (--num > last)
                {
                    if (++i < _pend.size())
                    {
                        insertion.push_back(num);
                    }
                    else
                    {
                        break; // Break the loop if we are about to exceed the list size
                    }
                }
                last = *jacobIt;
            }
        }
    }
    _insertionSequence = insertion;
    // std::cout << "insertion seq generated" << std::endl;
}

std::list<int> PmergeList::generateJacobsthalSequence(void)
{
    std::list<int> jacobsthal(_size);

    if (_size > 0)
        jacobsthal.push_back(0);
    if (_size > 1)
        jacobsthal.push_back(1);
    if (_size > 2)
    {
        std::list<int>::iterator prev2 = jacobsthal.begin();      // Points to the 0th element
        std::list<int>::iterator prev1 = jacobsthal.begin();      // Points to the 1st element (after increment)
        ++prev1;

        for (int i = 2; i < _size; ++i)
        {
            int new_val = *prev1 + 2 * (*prev2);
            jacobsthal.push_back(new_val);

            ++prev2;
            ++prev1;
        }
    }

    return jacobsthal;
}

void PmergeList::sortPairs()
{
    //mergeSort(_pairs, 0, _pairs.size() - 1);

    _pairs.sort();
    // //debug print
    // std::cout << "sorted pairs: " << "size " << _pairs.size() << " ";
    // for (std::list<std::pair<int, int> >::const_iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    // {
    //     std::cout << "(" << it->first << ", " << it->second << ") ";
    // }

    // std::cout << std::endl;
}

void PmergeList::divideChains()
{
    // Clear any existing elements in _mainChain and _pend
    _mainChain.clear();
    _pend.clear();

    if (!_pairs.empty())
    {
        // Add the second element of the first pair to _mainChain
        _mainChain.push_back(_pairs.front().second);

        std::list<std::pair<int, int> >::iterator pairsIt = _pairs.begin();

        for (; pairsIt != _pairs.end(); ++pairsIt)
        {
            // Add the first element of each pair to _mainChain
            _mainChain.push_back(pairsIt->first);

            // Add the second element to _pend if it's not the first pair
            if (pairsIt != _pairs.begin())
            {
                _pend.push_back(pairsIt->second);
            }
        }

        // // Debug print
        // std::cout << "_mainChain:";
        // for (std::list<int>::iterator mainIt = _mainChain.begin(); mainIt != _mainChain.end(); ++mainIt)
        // {
        //     std::cout << " " << *mainIt;
        // }
        // std::cout << std::endl;

        // std::cout << "_pend:";
        // for (std::list<int>::iterator pendIt = _pend.begin(); pendIt != _pend.end(); ++pendIt)
        // {
        //     std::cout << " " << *pendIt;
        // }
        // std::cout << std::endl;

        // std::cout << "Chains divided" << std::endl;
    }
}

std::list<int>::iterator	PmergeList::findPositionInMain(const int &i)
{
	std::list<int>::iterator it = _mainChain.begin();

	while (it != _mainChain.end() && *it < i)
        ++it;
    
	return (it);
}

void PmergeList::insertSort()
{
    std::list<int>::iterator positionInMain;

    // Loop through the insertion sequence
    for (std::list<int>::iterator it = _insertionSequence.begin(); it != _insertionSequence.end(); ++it)
    {
        int index = *it - 2;

    //     // Ensure the index is valid and within bounds
    //     if (index >= 0 && index < static_cast<int>(_pend.size()))
    //     {
    //         positionInMain = findPositionInMain(_pend[index]);
    //         _mainChain.insert(positionInMain, _pend[index]);
    //         // std::cout << "Inserted _pend[" << index << "] = " << _pend[index] << std::endl;
    //     }
        if (index >= 0)
        {
            // Traverse _pend to get the value at the calculated index
            std::list<int>::iterator pendIt = _pend.begin();
            std::advance(pendIt, index);

            // Ensure the iterator is within bounds
            if (pendIt != _pend.end())
            {
                positionInMain = findPositionInMain(*pendIt);
                _mainChain.insert(positionInMain, *pendIt);
                // std::cout << "Inserted _pend[" << index << "] = " << *pendIt << std::endl;
            }
        }
    }
    // Ensure all elements in _pend are inserted into _mainChain
    int i = 0;
    for (std::list<int>::iterator pendIt = _pend.begin(); pendIt != _pend.end(); ++pendIt, ++i)
    {
        if (std::find(_insertionSequence.begin(), _insertionSequence.end(), i + 2) == _insertionSequence.end())
        {
            positionInMain = findPositionInMain(*pendIt);
            _mainChain.insert(positionInMain, *pendIt);
            // std::cout << "Ensured insertion of _pend[" << i << "] = " << *pendIt << std::endl;
        }
    }
    // Insert _oddNum if it's non-negative
    if (_oddNum >= 0)
    {
        positionInMain = findPositionInMain(_oddNum);
        _mainChain.insert(positionInMain, _oddNum);
        // std::cout << "Odd number inserted: " << _oddNum << std::endl;
    }
    
}

void PmergeList::mergeInsertSort()
{
    if (!_pairs.empty())
    {
        sortPairs();
        divideChains();
        generateInsertionSequence();
        insertSort();
    }
    else
    {
        std::list<int> mainChain(1, _oddNum);
       _mainChain = mainChain;
    }
    _endTime = clock();

}

void PmergeList::getTime(void) const
{
    double _duration = double(_endTime - _startTime) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _size << " elements with std::list : " <<  _duration * 1000 << " us" << std::endl;
}

//UGLY MERGE SORT ALGORITHM
// void PmergeList::sortPairs(void)//change for the merge sort algorithm!
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


// void PmergeList::merge(std::list<std::pair<int, int> >& arr, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     std::list<std::pair<int, int> > L(n1);
//     std::list<std::pair<int, int> > R(n2);

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
// void PmergeList::mergeSort(std::list<std::pair<int, int> >& arr, int left, int right)
// {
//     if (left < right) {
//         int mid = left + (right - left) / 2;

//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         merge(arr, left, mid, right);
//     }
// }
