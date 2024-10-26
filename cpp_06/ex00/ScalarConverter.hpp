/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/26 16:24:38 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
 #ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>

typedef enum e_type
{
    CHAR, 
    INT,
    FLOAT,
    DOUBLE
}d_type;

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
        static	void convert(std::string arg);
};

 #endif