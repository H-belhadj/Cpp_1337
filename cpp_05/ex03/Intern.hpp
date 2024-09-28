/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:17:24 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/28 13:24:38 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



class Intern
{
    private:
        AForm   *CreatePresidentialPardonForm(std::string target);
        AForm   *CreateRobotomyRequestForm(std::string target);
        AForm   *CreateShrubberyCreationForm(std::string target);

    public:
        Intern();
        ~Intern();
        AForm *makeForm(std::string type, std::string target);
};
    typedef AForm *(Intern::*ft_ptr)(std::string);
#endif