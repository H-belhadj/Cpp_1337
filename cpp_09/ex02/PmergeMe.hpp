#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> Vec_;
    std::deque<int> deq_;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& obj);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    bool addNumberToContainer(int number);
    void printBefore() const;
    void printAfter() const;
    bool start(char **argv, int argc);
};

#endif