/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:37 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/15 22:38:43 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string Target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    void execute(Bureaucrat const & executor) const;

};

#endif