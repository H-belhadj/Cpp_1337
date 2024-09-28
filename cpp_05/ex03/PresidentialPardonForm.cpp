/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:34 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/28 10:01:08 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("PresidentialPardonForm", 25, 5), target(Target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
    *this = obj;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    (void)obj;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    (void) executor;
     if (this->isSigned()) {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    } else {
        throw NotSignedException(); // or some appropriate error handling
    }
}