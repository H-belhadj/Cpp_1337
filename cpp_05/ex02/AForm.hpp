/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:08 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/15 17:07:23 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool siGned;
        unsigned int signGrade;
        unsigned int execGrade;
    public:
        AForm();
        AForm(const std::string& name, unsigned int signgrade, unsigned int execgrade);    
        virtual ~AForm();
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "AForm ERROR : Grade Too Low";
                }
            
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "AForm ERROR : Grade Too High";
                }
        };

        class NotSignedException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return "AForm ERROR : NotSigned";
                }
        };
        //Getters
        std::string getName() const;
        bool isSigned() const;
        unsigned int getSigngrade() const;
        unsigned int getExecGrade() const;
        void beSigned(Bureaucrat &bureaucrat);
        void ExecCheck(Bureaucrat const& executor) const;

        virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& COUT, AForm const& other);

#endif