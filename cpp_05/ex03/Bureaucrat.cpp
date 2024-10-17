/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:00 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/17 11:19:17 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade() {}

Bureaucrat::Bureaucrat(const std::string& Name, int Grade) : name(Name), grade(Grade)
{
    if(Grade > 150)
        throw GradeTooLowException();
    else if(Grade < 1)
        throw GradeTooHighException();
    else
        this->grade = Grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::decrementGrade()
{
    if(this->grade >= 150)
        throw GradeTooLowException();
    else
        this->grade++;
}
void Bureaucrat::incrementGrade()
{
    if(this->grade <= 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "ERROR : GradeTooLow";
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "ERROR : GradeTooHigh";
}
void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& COUT, Bureaucrat const& other)
{
    COUT << other.getName() << " ,Bueaucat Grade " << other.getGrade();
    return COUT;
}

void    Bureaucrat::FormExecute(AForm const & Form)
{
    try
    {
        Form.execute(*this);
        std::cout << name << " executed " << Form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name << " couldn't execute " << Form.getName() << std::endl;
    }
}