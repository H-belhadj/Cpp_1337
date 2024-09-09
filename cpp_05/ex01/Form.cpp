/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:49 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/09 17:39:13 by hbelhadj         ###   ########.fr       */
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
std::string Form::getName()
{
    return name;
}
bool Form::isSigned()
{
    return siGned;
}
unsigned int Form::getSigngrade()
{
    return signGrade;
}
unsigned int Form::getExecGrade()
{
    return execGrade;
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= signGrade)
        siGned = true;
    else
        GradeTooLowException();
}
std::ostream& operator<<(std::ostream& COUT, Form &Form)
{
    COUT <<"Form : " << Form.getName() << " ,Grade To Sign:  " << Form.getSigngrade() << ", Grade To Execute: " << Form.getExecGrade() ;
    return COUT;
}