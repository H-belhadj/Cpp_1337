/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:16:55 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/17 10:45:08 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm() : name("Default"), siGned(false), signGrade(150), execGrade(150){}

AForm::AForm(const std::string& Name, unsigned int signgrade, unsigned int execgrade) : name(Name), siGned(false), signGrade(signgrade), execGrade(execgrade)
{
    if (signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    if (signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
}
AForm::~AForm() {}

//Getter Functions
std::string AForm::getName() const
{
    return name;
}
bool AForm::isSigned() const
{
    return siGned;
}
unsigned int AForm::getSigngrade() const
{
    return signGrade;
}
unsigned int AForm::getExecGrade() const
{
    return execGrade;
}
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= signGrade)
        siGned = true;
    else
        throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& COUT, const AForm &AForm)
{
    COUT <<"Form Name : " << AForm.getName() << ", Grade To Sign:  {" << AForm.getSigngrade() << "}, Grade To Execute: {" << AForm.getExecGrade() << "}" << std::endl; ;
    return COUT;
}

void AForm::ExecCheck(Bureaucrat const& executor) const
{
    if(executor.getGrade() > this->execGrade)
        throw GradeTooHighException();
    if(!this->isSigned())
        throw NotSignedException();
}