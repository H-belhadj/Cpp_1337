/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:06 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/14 17:59:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat b1("Bureaucrat 1", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        b1.incrementGrade();
        // std::cout << b1 << std::endl;
        // Bureaucrat b2("Bureaucrat 2", 1);
        // std::cout << b2 << std::endl;
        // // Bureaucrat b3("burau2", -1);
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}