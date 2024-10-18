/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/18 14:12:58 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"




#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Creating Bureaucrats
        Bureaucrat Haitam("Haitam", 50);
        Bureaucrat Siham("Siham", 1);
        
        // Creating Forms
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("criminal");

        // // Signing Forms
        std::cout << "========Signing forms========" << std::endl;;
        Haitam.signForm(shrubberyForm);  // Should succeed
        Haitam.signForm(robotomyForm);   // Should succeed
        Haitam.signForm(pardonForm);    // Should fail (grade too low)
        Siham.signForm(shrubberyForm);  // Should succeed
        Siham.signForm(robotomyForm);  // Should succeed
        Siham.signForm(pardonForm);    // Should succeed

        // // Executing Forms
        std::cout << "========Executing forms========" << std::endl;
        Siham.FormExecute(shrubberyForm);  // Should succeed
        Haitam.FormExecute(robotomyForm);    // Should fail (grade too low)
        Siham.FormExecute(robotomyForm);   // Should succeed, with 50% chance of success/failure
        Siham.FormExecute(pardonForm);     // Should succeed

    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


