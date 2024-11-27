/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:46:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/15 17:46:29 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <iterator>

class Span
{
    public:
        Span(unsigned int n);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
    
    private:
        std::vector<int> _vec;
        unsigned int _maxSize;
    
        class FullException : public std::exception
        {
            public:
                const char *what() const throw()
                { 
                    return "Span is full"; 
                }
        };
        class NoSpanException : public std::exception
        {
            public:
                const char *what() const throw()
                { 
                    return "No span to find";
                }
    };
};

#endif
