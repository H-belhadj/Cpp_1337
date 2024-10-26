/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:54 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/26 15:55:02 by hbelhadj         ###   ########.fr       */
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
    int point = 0;
    int flag = 0;
    int start = 0;
    if(str[0] == '-' || str[0] == '+')
        start = 1;
    for(int i = start; i < str.length(); i++)
    {
        if(str[i] =='.')
        {
            if(point || i == start || i == str.length() - 1 || !isdigit(str[i + 1] || !isdigit(str[i - 1])))
                return false;
            point = 1;
        }
        else if(str[i] == 'f')
        {
            if(flag || i != str.length() - 1)
                return false;
            flag = 1;
        }
        else if (!isdigit(str[i]))
            return false;
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
    int i = 0;
    double v = std::atof(arg.c_str());
    if(v > INT_MAX || v < INT_MIN)
        return false;
    int start = 0;
    if(arg[0] == '-' || arg[0] == '+')
        start = 1;
    for(int i = start; i < arg.length(); i++)
        if(!isdigit(arg[i]))
            return false;
    return true;
}

bool ft_char(std::string arg)
{
    if(arg.length() == 1)
        return !isdigit(arg[0]);
    for(int i = 0 ; i < arg.length() ; i++)
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