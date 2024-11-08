/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:54 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 21:35:43 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

bool one_dot(std::string str)
{
    size_t point = 0;
    size_t flag = 0;
    size_t start = 0;

    if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }

    for (size_t i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            if (point || i == start || i == str.length() - 1 || !isdigit(str[i + 1]) || !isdigit(str[i - 1])) {
                return false;
            }
            point = 1;
        } else if (str[i] == 'f') {
            if (flag || i != str.length() - 1 || point == 0) { // Ensure 'f' is at the end and that there is a decimal point
                return false;
            }
            flag = 1;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}


bool ft_float(std::string str)
{
    int len = str.length();
    return (str[len - 1] == 'f');
}

bool ft_int(std::string arg)
{
    double v = std::atof(arg.c_str());
    if(v > INT_MAX || v < INT_MIN)
        return false;
    int start = 0;
    if(arg[0] == '-' || arg[0] == '+')
        start = 1;
    for(size_t i = start; i < arg.length(); i++)
        if(!isdigit(arg[i]))
            return false;
    return true;
}

bool ft_char(std::string arg)
{
    if(arg.length() == 1)
        return !isdigit(arg[0]);
    for(size_t i = 0 ; i < arg.length() ; i++)
        if(!isdigit(arg[i]))
            return false;
    int value = std::atoi(arg.c_str());
    return isprint(value);
}
d_type ft_type(std::string arg)
{
    if(ft_float(arg))
        return FLOAT;
    if(ft_int(arg))
        return INT;
    if(ft_char(arg))
        return CHAR;
    return DOUBLE;
}
void ft_cast_char(std::string arg)
{
    char    v_char;
    int     v_int;
    float   v_float;
    double  v_double;
    
    //check if the single character
    if(arg.length() == 1 && !isdigit(arg[0]))
    {
        v_char = arg[0];
        v_int = static_cast<int>(v_char);
        v_float = static_cast<float>(v_char);
        v_double = static_cast<double>(v_char);
    }
    else
    {
        v_int = std::atoi(arg.c_str());
        v_char = static_cast<char>(v_int);
        v_float = static_cast<float>(v_int);
        v_double = static_cast<double>(v_int);
    }
    
    //print conversions
    std::cout << "char: '" << v_char << "'" << std::endl;
    std::cout << "int: " << v_int << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << v_float << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << v_double << std::endl;
}
void ft_cast_int(std::string arg)
{
    char    v_char;
    int     v_int = std::atoi(arg.c_str());
    float   v_float = static_cast<float>(v_int);
    double  v_double = static_cast<double>(v_int);

    if(!isprint(v_int))
    {
        v_char = static_cast<char>(v_int);
        std::cout << "char: '" << v_char << "'" << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << v_int << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << v_float << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << v_double << std::endl;
}
void ft_cast_float(std::string arg)
{
    char    v_char;
    float   v_float = std::atof(arg.c_str());
    int     v_int = static_cast<int>(v_float);
    double  v_double = static_cast<double>(v_float);

    if(isprint(static_cast<int>(v_float)))
    {
        v_char = static_cast<char>(v_float);
        std::cout << "char: '" << v_char << "'" << std::endl;
    }
    else
        std::cout << "char: Non Displayable" <<std::endl;

    if(v_float > INT_MAX || v_float < INT_MIN)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int: " << v_int << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << v_float << "f" << std::endl;
    std::cout <<"double: " << std::fixed << std::setprecision(2) << v_double << std::endl;
}

void ft_cast_double(std::string arg)
{
    char    v_char;
    double  v_double = std::atof(arg.c_str());
    int     v_int = static_cast<int>(v_double);
    float   v_float = static_cast<float>(v_double);

    if(isprint(static_cast<int>(v_double)))
    {
        v_char = static_cast<char>(v_double);
        std::cout << "char: '" << v_char << "'" << std::endl;
    }
    else
        std::cout << "char: Non Displayable" <<std::endl;

    if(v_double > INT_MAX || v_double < INT_MIN)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int: " << v_int << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << v_float << "f" << std::endl;
    std::cout <<"double: " << std::fixed << std::setprecision(2) << v_double << std::endl;
}

bool ft_pseudo(std::string arg)
{
    if (arg == "+inf" || arg == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    
    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    
    if (arg == "nan" || arg == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert(std::string arg)
{
        if (ft_pseudo(arg)) return;

    // Check for invalid float representation with multiple dots
    if (!one_dot(arg)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    d_type type = ft_type(arg);
    switch (type) {
        case CHAR:
            ft_cast_char(arg);
            break;
        case INT:
            ft_cast_int(arg);
            break;
        case FLOAT:
            ft_cast_float(arg);
            break;
        case DOUBLE:
            ft_cast_double(arg);
            break;
        default:
            std::cout << "Sorry, wrong input." << std::endl;
            break;
    }
}
