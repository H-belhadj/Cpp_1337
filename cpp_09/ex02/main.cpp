#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return 1;
    }

    PmergeMe pmm;
    pmm.start(argv, argc);

    return 0;
}