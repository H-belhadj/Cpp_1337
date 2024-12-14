#include "PmergeMe.hpp"
#include <chrono>
#include <algorithm>
#include <iostream>

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

const std::vector<int>& PmergeMe::getVector() const
{
    return Vec_;
}

const std::deque<int>& PmergeMe::getDeque() const
{
    return deq_;
}

bool PmergeMe::addNumberToContainer(int number)
{
    this->Vec_.push_back(number);
    this->deq_.push_back(number);
    return true;
}

void PmergeMe::sortVector()
{
    std::chrono::high_resolution_clock::time_point startVec = std::chrono::high_resolution_clock::now();
    sortVectorUsingMerge(0, Vec_.size() - 1);
    std::chrono::high_resolution_clock::time_point endVec = std::chrono::high_resolution_clock::now();
    this->time_Vec = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec).count();
}

void PmergeMe::sortDeque()
{
    std::chrono::high_resolution_clock::time_point startDeq = std::chrono::high_resolution_clock::now();
    sortDequeUsingMerge(0, deq_.size() - 1);
    std::chrono::high_resolution_clock::time_point endDeq = std::chrono::high_resolution_clock::now();
    this->time_Deque = std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq).count();
}

void PmergeMe::sortVectorUsingMerge(int first, int last)
{
    if (first < last)
    {
        int middle = first + (last - first) / 2;
        sortVectorUsingMerge(first, middle);
        sortVectorUsingMerge(middle + 1, last);
        mergeVector(first, middle, last);
    }
}

void PmergeMe::sortDequeUsingMerge(int first, int last)
{
    if (first < last)
    {
        int middle = first + (last - first) / 2;
        sortDequeUsingMerge(first, middle);
        sortDequeUsingMerge(middle + 1, last);
        mergeDeque(first, middle, last);
    }
}

void PmergeMe::mergeVector(int first, int middle, int last)
{
    int n1 = middle - first + 1;
    int n2 = last - middle;

    // Create temporary arrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = Vec_[first + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = Vec_[middle + 1 + j];

    // Merge the temporary arrays back into Vec_[first..last]
    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            Vec_[k] = leftArray[i];
            i++;
        }
        else
        {
            Vec_[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray[] if any
    while (i < n1)
    {
        Vec_[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray[] if any
    while (j < n2)
    {
        Vec_[k] = rightArray[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeDeque(int first, int middle, int last)
{
    int n1 = middle - first + 1;
    int n2 = last - middle;

    // Create temporary arrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = deq_[first + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = deq_[middle + 1 + j];

    // Merge the temporary arrays back into deq_[first..last]
    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            deq_[k] = leftArray[i];
            i++;
        }
        else
        {
            deq_[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray[] if any
    while (i < n1)
    {
        deq_[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray[] if any
    while (j < n2)
    {
        deq_[k] = rightArray[j];
        j++;
        k++;
    }
}

bool is_number(const std::string &s) {
    if (s.empty())
        return false;
    size_t start = 0;

    if (s[0] == '+') {
        if (s.length() == 1)
            return false;
        start = 1;
    }

    for (size_t i = start; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void PmergeMe::start(char **argv, int argc)
{
    for (int i = 1; i < argc; i++)
    {
        if (is_number(argv[i]))
        {
            addNumberToContainer(std::stoi(argv[i]));
        }
        else
        {
            std::cout << "Invalid input: " << argv[i] << std::endl;
        }
    }
    sortVector();
    sortDeque();
    std::cout << "Vector: ";
    for (size_t i = 0; i < Vec_.size(); i++)
        std::cout << Vec_[i] << " ";
    std::cout << std::endl;
    std::cout << "Deque: ";
    for (size_t i = 0; i < deq_.size(); i++)
    {
        std::cout << deq_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken to sort vector: " << time_Vec << " microseconds" << std::endl;
    std::cout << "Time taken to sort deque: " << time_Deque << " microseconds" << std::endl;
}