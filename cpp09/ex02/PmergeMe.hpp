#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <utility>

class PmergeMe
{
    private:
        int _oddNum;
        int _size;
        std::vector<int> _unsorted;
        std::vector<std::pair<int, int>> _pairs;
        std::vector<int> _sorted;
        std::vector<int> _insertionSequence; 
        
        //void print(void) const;
        std::vector<int> generateJacobsthalSequence(void);
        std::vector<int> generateInsertionSequence(void);

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
