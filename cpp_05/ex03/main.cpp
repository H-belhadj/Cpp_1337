/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/28 13:46:10 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" // Assuming these files exist

int main() {
    // Create a bureaucrat with name "Bob" and grade 150 (low grade)
    Bureaucrat bob("Bob", 150);

    // Create forms
    PresidentialPardonForm presidentialPardon("Target1");
    RobotomyRequestForm robotomyRequest("Target2");
    ShrubberyCreationForm shrubberyCreation("Target3");

    // Bob (low grade) cannot sign any forms
    bob.signForm(presidentialPardon);
    bob.signForm(robotomyRequest);
    bob.signForm(shrubberyCreation);

    // Create a bureaucrat with name "Alice" and grade 1 (high grade)
    Bureaucrat alice("Alice", 1);

    // Alice (high grade) can sign all forms
    alice.signForm(presidentialPardon);
    alice.signForm(robotomyRequest);
    alice.signForm(shrubberyCreation);

    // Alice (high grade) can execute all signed forms (assuming implementations)
    alice.FormExecute(presidentialPardon);
    alice.FormExecute(robotomyRequest);
    alice.FormExecute(shrubberyCreation);

    return 0;
}