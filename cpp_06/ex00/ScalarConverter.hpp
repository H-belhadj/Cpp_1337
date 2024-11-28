/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/20 21:49:59 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <cstdlib>

typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
} d_type;

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        
        static bool isValidFloat(const std::string& str);
        static bool isValidInt(const std::string& str);
        static bool isValidChar(const std::string& str);
        static bool isPseudoLiteral(const std::string& str);
        static d_type determineType(const std::string& str);
        
        static void convertChar(const std::string& arg);
        static void convertInt(const std::string& arg);
        static void convertFloat(const std::string& arg);
        static void convertDouble(const std::string& arg);
        static void handlePseudoLiteral(const std::string& arg);
    
    public:
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
        static void convert(const std::string& arg);
};

#endif