/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:06 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/08/26 10:49:32 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
    try {
        Bureaucrat bureaucrat("haitam", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
