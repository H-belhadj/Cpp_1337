/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:24:48 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/08/26 10:25:21 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NAME"), grade(1)
{
    
}
Bureaucrat::Bureaucrat(const std::string Name, int Grade) : name(Name), grade(Grade)
{
    if(Grade > this->minGrade)
        throw GradeTooLowException();
    else if(Grade > this->maxGrade)
        throw GradeTooHighException();
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

Bureaucrat::~Bureaucrat()
{
    
}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade >= this->minGrade)
        throw GradeTooLowException();
    else
        this->grade++;
}
void Bureaucrat::incrementGrade()
{
    if(this->grade <= this->maxGrade)
        throw GradeTooHighException();
    else
        this->grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
const char* Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Grade is too high";
}
std::ostream& operator<<(std::ostream& COUT, Bureaucrat const& other)
{
    COUT<<other.getName()<<", Bueaucat Gade"<<other.getGrade();
    return COUT
}