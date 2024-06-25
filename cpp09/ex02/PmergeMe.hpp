#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>

class PmergeMe
{
    private:
        void print(void) const;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &source);
        PmergeMe &operator=(const PmergeMe &source);
        ~PmergeMe();
};

#endif // PMERGEME_HPP
