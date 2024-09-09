/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:46 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/09 17:43:36 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool siGned;
        unsigned int signGrade;
        unsigned int execGrade;
    public:
        Form();
        Form(const std::string& name, unsigned int signgrade, unsigned int execgrade);    
        ~Form();
        

        //exception
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form ERROR : Grade Too Low";
                }
            
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form ERROR : Grade Too High";
                }
        };
        //Getters
        std::string getName();
        bool isSigned();
        unsigned int getSigngrade();
        unsigned int getExecGrade();
        void beSigned(Bureaucrat &bureaucrat);
};
std::ostream& operator<<(std::ostream& COUT, Form const& other);

#endif