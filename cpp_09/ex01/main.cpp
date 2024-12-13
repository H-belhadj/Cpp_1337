#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " \"[expression]\"" << std::endl;
        return (EXIT_FAILURE);
    }

    RPN::calc(av[1]); // Use the correct method to calculate the expression

    return (EXIT_SUCCESS);
}
