/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:35 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/27 15:54:21 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137), target(Target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
    *this = obj;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    (void) obj;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!this->getSigngrade())
        throw NotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else
    {
        std::string name = executor.getName() + "shrubbery";
        std::ofstream ofs(name);
        ofs << "        *        " << std::endl;
        ofs << "       ***       " << std::endl;
        ofs << "      *****      " << std::endl;
        ofs << "     *******     " << std::endl;
        ofs << "    *********    " << std::endl;
        ofs << "   ***********   " << std::endl;
        ofs << "  *************  " << std::endl;
        ofs << " *************** " << std::endl;
        ofs << "*****************" << std::endl;
        ofs << "       |||       " << std::endl;
        ofs << "       |||       " << std::endl;
        ofs << "       |||       " << std::endl;
        ofs << "       |||       " << std::endl;
        ofs.close();
    }
    
}