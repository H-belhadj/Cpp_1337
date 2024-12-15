#include "PmergeMe.hpp"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    Vec_ = obj.Vec_;
    deq_ = obj.deq_;
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        Vec_ = rhs.Vec_;
        deq_ = rhs.deq_;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::addNumberToContainer(int number)
{
    if (number < 0) {
        return false;
    }
    Vec_.push_back(number);
    deq_.push_back(number);
    return true;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < Vec_.size(); ++i) {
        std::cout << Vec_[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (std::vector<int>::size_type i = 0; i < Vec_.size(); ++i) {
        std::cout << Vec_[i] << " ";
    }
    std::cout << std::endl;
}

double getTimeDiff(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
}

bool PmergeMe::start(char **argv, int argc)
{
    std::vector<int> inputNumbers;

    // Validate and store input numbers
    for (int i = 1; i < argc; ++i) {
        char* endptr;
        long num = std::strtol(argv[i], &endptr, 10);

        // Check for conversion errors
        if (*argv[i] == '\0' || *endptr != '\0') {
            std::cout << "Error" << std::endl;
            return false;
        }

        // Check for negative or out of range numbers
        if (num < 0 || num > std::numeric_limits<int>::max()) {
            std::cout << "Error" << std::endl;
            return false;
        }

        inputNumbers.push_back(static_cast<int>(num));
    }

    // If no valid numbers, return false
    if (inputNumbers.empty()) {
        std::cout << "Error" << std::endl;
        return false;
    }

    // Copy input to member containers
    Vec_ = inputNumbers;
    deq_ = std::deque<int>(inputNumbers.begin(), inputNumbers.end());

    // Print before sorting
    printBefore();

    // Sort vector
    clock_t startVec = clock();
    std::sort(Vec_.begin(), Vec_.end());
    clock_t endVec = clock();

    // Sort deque
    clock_t startDeq = clock();
    std::sort(deq_.begin(), deq_.end());
    clock_t endDeq = clock();

    // Print after sorting
    printAfter();

    // Print time taken
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << Vec_.size() 
              << " elements with std::vector : " << getTimeDiff(startVec, endVec) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq_.size() 
              << " elements with std::deque : " << getTimeDiff(startDeq, endDeq) << " us" << std::endl;

    return true;
}