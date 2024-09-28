/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:21 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/28 13:37:58 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string type, std::string target)
{
    int x = -1;
    std::string str[] = {"presidential", "shrubbery", "robotomy"};
    ft_ptr intern_ptr[3] = {&Intern::CreatePresidentialPardonForm, &Intern::CreateShrubberyCreationForm, &Intern::CreateRobotomyRequestForm};
    while(++x < 3)
    {
        if(type.find(str[x]) != std::string::npos)
        {
            std::cout << "Intern Createss" << std::endl;
            return (this->*intern_ptr[x])(target);
        }
    }
        std::cout << "ERROR" << std::endl;
        return NULL; 
}
AForm   *Intern::CreatePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}
AForm   *Intern::CreateRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);

}
AForm   *Intern::CreateShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}
