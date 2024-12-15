#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <chrono>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        std::chrono::duration<double, std::micro> _durationVec , _durationDeq; 

        bool addNumberToContainers(int number);
        void sortVector();
        void sortDeque();
        void sortVectorUsingMergeSort(int first, int last);
        void sortDequeUsingMergeSort(int first, int last);
        void mergeV(int first, int middle, int last);
        void mergeD(int first, int middle, int last);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        ~PmergeMe();
        void start(char **argv);
        const std::vector<int>& getVector() const;
        const std::deque<int>& getDeque() const;
};

#endif