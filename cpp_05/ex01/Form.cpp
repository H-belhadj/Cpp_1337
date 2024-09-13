/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:49 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/13 08:14:25 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form() : name("Default"), siGned(false), signGrade(150), execGrade(150){}

Form::Form(const std::string& name, unsigned int signgrade, unsigned int execgrade) : name("Default"), siGned(false), signGrade(signgrade), execGrade(execgrade)
{
    (void)name;
    if (signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    if (signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
}
Form::~Form() {}

//Getter Functions
std::string Form::getName() const
{
    return name;
}
bool Form::isSigned() const
{
    return siGned;
}
unsigned int Form::getSigngrade() const
{
    return signGrade;
}
unsigned int Form::getExecGrade() const
{
    return execGrade;
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= signGrade)
        siGned = true;
    else
        throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& COUT, const Form &Form)
{
    COUT <<"Form : " << Form.getName() << " ,Grade To Sign:  " << Form.getSigngrade() << ", Grade To Execute: " << Form.getExecGrade() ;
    return COUT;
}