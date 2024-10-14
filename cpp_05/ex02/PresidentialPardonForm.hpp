/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:27 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/14 19:05:46 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class AForm;
class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
    PresidentialPardonForm(const std::string Target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    void execute(Bureaucrat const & executor) const;

};

#endif