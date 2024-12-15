#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _durationVec(0), _durationDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}
PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
        _durationVec = src._durationVec;
        _durationDeq = src._durationDeq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getVector() const
{
    return _vec;
}
const std::deque<int>& PmergeMe::getDeque() const
{
    return _deq;
}
bool PmergeMe::addNumberToContainers(int number)
{
    _vec.push_back(number);
    _deq.push_back(number);
    return true;
}
void PmergeMe::mergeV(int first, int middle, int last)
{
    int n1 = middle - first + 1;
    int n2 = last - middle;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = _vec[first + i];
    for (int j = 0; j < n2; j++)
        R[j] = _vec[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = first;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            _vec[k] = L[i];
            i++;
        }
        else
        {
            _vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        _vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        _vec[k] = R[j];
        j++;
        k++;
    }
}
void PmergeMe::mergeD(int first, int middle, int last)
{
    int n1 = middle - first + 1;
    int n2 = last - middle;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = _deq[first + i];
    for (int j = 0; j < n2; j++)
        R[j] = _deq[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = first;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            _deq[k] = L[i];
            i++;
        }
        else
        {
            _deq[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        _deq[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        _deq[k] = R[j];
        j++;
        k++;
    }
}
void PmergeMe::sortVectorUsingMergeSort(int first, int last)
{
    if (first < last)
    {
        int middle = first + (last - first) / 2;
        sortVectorUsingMergeSort(first, middle);
        sortVectorUsingMergeSort(middle + 1, last);
        mergeV(first, middle, last);
    }
}
void PmergeMe::sortDequeUsingMergeSort(int first, int last)
{
    if (first < last)
    {
        int middle = first + (last - first) / 2;
        sortDequeUsingMergeSort(first, middle);
        sortDequeUsingMergeSort(middle + 1, last);
        mergeD(first, middle, last);
    }
}
void PmergeMe::sortVector()
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    sortVectorUsingMergeSort(0, _vec.size() - 1);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    this->_durationVec = end - start;
}
void PmergeMe::sortDeque()
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    sortDequeUsingMergeSort(0, _deq.size() - 1);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    this->_durationDeq = end - start;
}
bool is_number(const std::string &s)
{
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
        if (!std::isdigit(*it))
            return false;
    return true;
}
void PmergeMe::start(char **argv)
{
    _vec.clear();  // Clear existing data
    _deq.clear();  // Clear existing data

    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        if(!is_number(str))
        {
            std::cerr << "Error: Invalid input !" << std::endl;
            return ;
        }
        int number = std::stoi(str);
        if(!addNumberToContainers(number))
        {
            std::cerr << "Error: Invalid input !" << std::endl;
            return ;
        }
    }
    
    std::cout << "before: ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    if(_vec.size() == 2 && _vec[0] > _vec[1])
    {
        int temp = _vec[0];
        _vec[0] = _vec[1];
        _vec[1] = temp;
    }
    else if (_vec.size() > 2)
    {
        sortVector();
        sortDeque();
    }

    std::cout << "after: ";
    for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << this->_durationVec.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::deque: " << this->_durationDeq.count() << " us" << std::endl;
}