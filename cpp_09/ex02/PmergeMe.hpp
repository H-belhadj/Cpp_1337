#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <stdexcept>
#include <ctime>

class PmergeMe {
    private:
        std::vector<int> Vec_;
        std::deque<int> deq_;
        clock_t time_Vec;
        clock_t time_Deque;

        bool addNumberToContainer(int number);

        void sortVector();
        void sortDeque();

        void sortVectorUsingMerge(int first, int last);
        void sortDequeUsingMerge(int first, int last);

        void mergeVector(int first, int middle, int last);
        void mergeDeque(int first, int middle, int last);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        void start(char **argv, int argc);
        const std::vector<int>& getVector() const;
        const std::deque<int>& getDeque() const;
};

#endif