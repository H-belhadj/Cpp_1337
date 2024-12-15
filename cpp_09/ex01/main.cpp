#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"[expression]\"" << std::endl;
        return (0);
    }
    RPN::calc(argv[1]);
    return (0);
}
