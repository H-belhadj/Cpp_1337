/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/21 11:00:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
 #ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

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
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
};

 #endif