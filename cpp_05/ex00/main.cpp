/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:06 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/09 11:55:47 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat b1("burau1", -55);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        b1.incrementGrade();
        Bureaucrat b2("burau2", 1000);
        Bureaucrat b3("burau2", -1);
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}