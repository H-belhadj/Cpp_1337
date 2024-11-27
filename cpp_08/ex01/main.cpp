/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:24:37 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/15 17:24:37 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

void testSubject()
{
    std::cout << "=== Test Subject ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected: 2
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Expected: 14
}

void testExceptions()
{
    std::cout << "\n=== Test Exceptions ===" << std::endl;
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Span sp(1);
        sp.addNumber(10);
        std::cout << sp.shortestSpan() << std::endl; // Should throw exception
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testRange()
{
    std::cout << "\n=== Test Range Addition ===" << std::endl;
    std::vector<int> nums;
    for (int i = 0; i < 10; ++i)
        nums.push_back(i * 10);
    Span sp(15);
    sp.addRange(nums.begin(), nums.end());
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

int main()
{
    testSubject();
    testExceptions();
    testRange();
    return 0;
}
