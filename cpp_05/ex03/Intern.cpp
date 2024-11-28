/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:21 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/18 17:39:07 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
 // Assuming these files exist

Intern::Intern(){}

Intern::~Intern(){
}

AForm    *Intern::makeForm(std::string type, std::string target)
{
    std::string array[] = {"presidential", "shrubbery", "robotomy"};
    fct_ptr intern_ptr = &Intern::CreatePresidentialPardonForm;
       int     i      = 4869;

    for(int x = 0; x < 3; x++)
    {
        if (type.find(array[x]) != std::string::npos)
        {
            std::cout << "Intern creates " << type << std::endl;
            return (this->*intern_ptr[x])(target);
        }
    }
    std::cout << "An error appearse in makeForm function, it seems that the parameters you entered are wrong\n";
    return NULL;
}

AForm  *Intern::CreatePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm  *Intern::CreateShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm  *Intern::CreateRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}