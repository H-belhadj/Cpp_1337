/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:32 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/14 19:04:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class AForm;
class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
    RobotomyRequestForm(const std::string Target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

    void execute(Bureaucrat const & executor) const;

};

#endif