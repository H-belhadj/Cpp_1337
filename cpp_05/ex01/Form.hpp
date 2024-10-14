/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:46 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/14 18:19:26 by hbelhadj         ###   ########.fr       */
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
        const unsigned int signGrade;
        const unsigned int execGrade;
    public:
        Form();
        Form(const std::string& name, unsigned int signgrade, unsigned int execgrade);    
        ~Form();
        

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

        std::string getName() const;
        bool isSigned() const;
        unsigned int getSigngrade() const;
        unsigned int getExecGrade() const;
        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& COUT, Form const& other);

#endif