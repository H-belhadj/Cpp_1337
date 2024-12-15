#include "PmergeMe.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc < 3)
	{
        std::cout << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return 1;
    }

    PmergeMe sakan;
    sakan.start(argv, argc);

    return 0;
}