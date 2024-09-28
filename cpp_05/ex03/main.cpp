/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/28 15:21:06 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp" // Assuming these files exist

// int main() {
//     // Create a bureaucrat with name "Bob" and grade 150 (low grade)
//     Bureaucrat bob("Bob", 150);

//     // Create forms
//     PresidentialPardonForm presidentialPardon("Target1");
//     RobotomyRequestForm robotomyRequest("Target2");
//     ShrubberyCreationForm shrubberyCreation("Target3");

//     // Bob (low grade) cannot sign any forms
//     bob.signForm(presidentialPardon);
//     bob.signForm(robotomyRequest);
//     bob.signForm(shrubberyCreation);

//     // Create a bureaucrat with name "Alice" and grade 1 (high grade)
//     Bureaucrat alice("Alice", 1);

//     // Alice (high grade) can sign all forms
//     alice.signForm(presidentialPardon);
//     alice.signForm(robotomyRequest);
//     alice.signForm(shrubberyCreation);

//     // Alice (high grade) can execute all signed forms (assuming implementations)
//     alice.FormExecute(presidentialPardon);
//     alice.FormExecute(robotomyRequest);
//     alice.FormExecute(shrubberyCreation);

//     return 0;
// }

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// int	main( void )
// {
// 	try
// 	{
// 		Intern	someRandomIntern;
// 		AForm		*shrub;
// 		Bureaucrat	bob("Bob", 1);
// 		shrub	= someRandomIntern.makeForm("shrubbery creation", "home");
// 		shrub->beSigned(bob);
// 		shrub->execute(bob);
// 		std::cout << std::endl;
// 		std::cout << std::endl;

// 		Intern	someRandomIntern2;
// 		AForm		*presidential;
// 		presidential	= someRandomIntern2.makeForm("Some thing that doesnt work", "You");
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
	
// 	return (0);
// }

int main()
{
    Bureaucrat bureau;
    Intern someRandomIntern;
    AForm* form;
//---------------------------Should create tests---------------------------//
    std::cout << "should create president\n" ;
    form = someRandomIntern.makeForm("presidential quest", "Bender");
    
    std::cout << "\nshould create shrubbery\n" ;
    form = someRandomIntern.makeForm("shrubbery quest", "Bender");
    
    std::cout << "\nshould create robotomy\n" ;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    

//-------------------------Should not create tests-------------------------//
    std::cout << "\nshould not create president\n" ;
    form = someRandomIntern.makeForm("president quest", "Bender");

    std::cout << "\nshould not create shrubbery\n" ;
    form = someRandomIntern.makeForm("shrubery quest", "Bender");

    std::cout << "\nshould not create robotomy\n" ;
    form = someRandomIntern.makeForm("roboto request", "Bender");
}
