/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:40 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/16 19:34:14 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 72, 45), target(Target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
    *this = obj;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    (void) obj;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    ExecCheck(executor);
    std::cout << ".........  * DRILLING NOISE * ........." << std::endl;
    srand(time(0));
    if(rand() % 2 == 0)
        std::cout << target << " has been robotomized." << std::endl;
    else
        std::cout << target << " failed to be robotomized." << std::endl;
}