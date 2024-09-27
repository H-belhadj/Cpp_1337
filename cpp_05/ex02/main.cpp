/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/27 18:49:29 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Corrector", 1);
	Bureaucrat	me("Me", 140);

	corr.FormExecute(*shrub);
	std::cout << std::endl;
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.FormExecute(*shrub);
	me.FormExecute(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("Corrector");
	Bureaucrat	me2("Me", 1);

	me2.FormExecute(*robotomy);
	me2.signForm(*robotomy);
	me2.FormExecute(*robotomy);
	me2.FormExecute(*robotomy);
	me2.FormExecute(*robotomy);
	me2.FormExecute(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*presidential = new PresidentialPardonForm("Corrector");
	Bureaucrat	me3("Me", 6);

	me3.FormExecute(*presidential);
	me3.signForm(*presidential);
	me3.FormExecute(*presidential);
	me3.incrementGrade();
	me3.FormExecute(*presidential);
	delete presidential;

	return (0);
}