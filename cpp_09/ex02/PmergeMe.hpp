#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>
#include <ctime>

template <typename container>
class PmergeMe
{
public:
    typedef typename container::value_type      v_type;
    typedef std::pair<v_type, v_type>           p_type;

private:
    container                   data;
    container                   pend;
    container                   seqnbr;
    double                      time;
    std::vector<p_type>         pairs;

    bool    isnbr(std::string str);
    void    generate(size_t size, container &seqnbr);

    PmergeMe(void);  // Private default constructor

public:
    PmergeMe(char **av);
    PmergeMe(const PmergeMe& obj);
    PmergeMe& operator=(const PmergeMe& obj);
    ~PmergeMe(void);

    void    DataDisplay(void);
    void    TimeDisplay(std::string ctype);
    void    sort(void);
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP