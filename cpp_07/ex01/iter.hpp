/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:26:47 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:26:47 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename Type, typename F>
void iter(Type *array, int size, void (*func)(F &))
{
    for (int i = 0; i < size; ++i)
        func(array[i]);
}
// template <typename Type> 
// void print(Type &val)
// {
//     std::cout << val << std::endl;
// }
#endif


// Scenario	Your Function (2 Template Parameters)	Simpler Function (1 Template Parameter)

// Basic case: array of int elements, function expects int&.	✅ Works	✅ Works

// Array of const int elements, function expects int&.	✅ Works (handles const correctly)	❌ Fails (type mismatch)

// Array of double elements, function expects int& (type conversion).	✅ Works (converts double to int)	❌ Fails (type mismatch)

// Array of int elements, function expects const int&.	✅ Works	✅ Works

// Array of int elements, function expects a different type (e.g., std::string&).	✅ Works if explicit conversion exists	❌ Fails (type mismatch)

// Array of std::string elements, function expects std::string&.	✅ Works	✅ Works

// Array of const std::string elements, function expects std::string&.	✅ Works (handles const correctly)	❌ Fails (type mismatch)

// Array of std::string elements, function expects std::string&&.	❌ Fails (does not support rvalue refs)	❌ Fails (does not support rvalue refs)

// Function accepts a Type by value (e.g., void func(Type val)).	✅ Works	✅ Works


// Function accepts a Type by pointer (e.g., void func(Type* val)).	❌ Fails (expects Type&)	❌ Fails (expects Type&)

// Function is overloaded for different types.	✅ Works with explicit F	❌ Fails without specifying template type