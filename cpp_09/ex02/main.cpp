#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // For std::atoi

int main(int argc, char **argv) {
    PmergeMe Dexter;

    if (argc > 2)
        Dexter.start(argv);
    else 
        std::cout << "Usage: ./pmergeMe [number1] [number2] ..." << std::endl;
    return 0;
}