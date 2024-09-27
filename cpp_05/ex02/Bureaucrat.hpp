/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:17 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/27 11:26:47 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;


class Bureaucrat
{
    private:
        const std::string name;
        unsigned int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //getters
        const std::string getName() const;
        unsigned int getGrade() const;
        //public methods
        void incrementGrade();
        void decrementGrade();
        void	signForm(AForm& obj);
        //exceptions
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
            
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream& COUT, Bureaucrat const &other);

#endif