/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/17 11:27:27 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" // Assuming these files exist
#include "Intern.hpp"

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

int main()
{
    Bureaucrat bureau;
    Intern someRandomIntern;
    AForm* rrf;
//---------------------------Should create tests---------------------------//
    std::cout << ORANGE_TEXT << "should create president\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("presidential quest", "Bender");
    
    std::cout << ORANGE_TEXT << "\nshould create shrubbery\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("shrubbery quest", "Bender");
    
    std::cout << ORANGE_TEXT << "\nshould create robotomy\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    

//-------------------------Should not create tests-------------------------//
    std::cout << ORANGE_TEXT << "\nshould not create president\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("president quest", "Bender");

    std::cout << ORANGE_TEXT << "\nshould not create shrubbery\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("shrubery quest", "Bender");

    std::cout << ORANGE_TEXT << "\nshould not create robotomy\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("roboto request", "Bender");
}