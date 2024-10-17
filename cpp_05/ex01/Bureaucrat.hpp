/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/15 16:55:51 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;


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

        const std::string getName() const;
        unsigned int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void	signForm(Form& obj);

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
            
        };

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream& COUT, Bureaucrat const &other);

#endif