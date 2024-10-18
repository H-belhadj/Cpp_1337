/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/18 15:26:55 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Create an intern
        Intern someRandomIntern;
        
        // Bureaucrat for form execution
        Bureaucrat Haitam("Haitam", 1);

        // // Create some forms using the intern
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << "Intern created: " << form1->getName() << std::endl;

        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "Intern created: " << form2->getName() << std::endl;

        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "criminal");
        std::cout << "Intern created: " << form3->getName() << std::endl;

        // // Sign and execute forms
        Haitam.signForm(*form1);
        Haitam.FormExecute(*form1);

        Haitam.signForm(*form2);
        Haitam.FormExecute(*form2);

        // // Clean up dynamically allocated memory
        delete form1;
        delete form2;
        delete form3;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
