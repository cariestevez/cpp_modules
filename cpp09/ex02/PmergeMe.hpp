#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <utility>
#include <limits>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
    private:
        int _oddNum;
        int _size;
        std::vector<int> _mainChain;
        // std::list<int> _mainChainList;
        std::vector<int> _pend;
        // std::list<int> _pendList;
        std::vector<std::pair<int, int> > _pairs;
        std::vector<int> _insertionSequence; 
        
        int convertToInt(char *numString);
        void sortPairs();
        void divideChains();
        void generateInsertionSequence(void);
        std::vector<int> generateJacobsthalSequence(void);
        void insertSort();
        std::vector<int>::iterator findPositionInMain(const int &i);
        // void merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right);
        // void mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right);

    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &source);
        PmergeMe &operator=(const PmergeMe &source);
        ~PmergeMe(void);

        void mergeInsertSort();
        void print(void) const;
        int getVecTime(void) const;
        int getLstTime(void) const;
};

#endif // PMERGEME_HPP
