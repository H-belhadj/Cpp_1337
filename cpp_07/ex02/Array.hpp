/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:30:48 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/24 13:30:48 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename Type>
class Array
{
    private:
        Type *_array;
        unsigned int _size;
    public:    
        Array();
        Array(unsigned int n);
        Array(Array const &obj);
        Array &operator=(Array const &rhs);
        ~Array();

        unsigned int size() const;

        Type &operator[](unsigned int index);
        const Type &operator[](unsigned int index) const;

        class OutOfLimitsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif

