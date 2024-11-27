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

class Span {
public:
    // Constructors & Destructor
    Span(unsigned int n);                // Parameterized constructor
    Span(const Span &src);               // Copy constructor
    Span &operator=(const Span &src);    // Assignment operator
    ~Span();                             // Destructor

    // Member functions
    void addNumber(int n);   // Add a single number
    void addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end); // Add numbers from range
    int shortestSpan() const;  // Calculate shortest span
    int longestSpan() const;   // Calculate longest span

private:
    std::vector<int> _vec;
    unsigned int _maxSize;

    // Exception classes
    class FullException : public std::exception {
    public:
        const char *what() const throw()
        { 
            return "Span is full"; 
        }
    };
    class NoSpanException : public std::exception {
    public:
        const char *what() const throw()
        { 
            return "No span to find"; }
    };
};

#endif // SPAN_HPP
