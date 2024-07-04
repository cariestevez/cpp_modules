#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe
{
    private:
        int _oddNum;
        std::vector<int> _unsorted;
        std::vector<int> _sorted;
        std::vector<int> _insertionSequence; 
        
        //void print(void) const;
        std::vector<int> generateJacobsthalSequence(int n);
        std::vector<int> generateInsertionSequence(int n);

    public:
        PmergeMe(std::vector<int> &userInput);
        PmergeMe(const PmergeMe &source);
        PmergeMe &operator=(const PmergeMe &source);
        ~PmergeMe(void);

        void mergeInsertSort();
        void print(void) const;
        int getVecTime(void) const;
        int getLstTime(void) const;
};

#endif // PMERGEME_HPP
