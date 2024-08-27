/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:00 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/08/27 18:05:24 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //getters
        std::string const getName() const;
        unsigned int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();

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