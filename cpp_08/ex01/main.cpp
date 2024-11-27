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

int main()
{
    try
    {
        Span spLarge(10000);
        for (int i = 0; i < 10000; ++i)
        {
            spLarge.addNumber(i * 2);
        }
        std::cout << "Shortest Span: " << spLarge.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spLarge.longestSpan() << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
