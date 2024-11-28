#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span shobee(10000);
        for (int i = 0; i < 10000; ++i)
        {
            shobee.addNumber(i * 2);
        }
        std::cout << "Shortest Span: " << shobee.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << shobee.longestSpan() << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
