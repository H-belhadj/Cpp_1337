/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:54 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

bool ScalarConverter::isValidFloat(const std::string& str)
{
    size_t dotCount = 0;
    size_t start = 0;

    //Allowing optional sign
    if (str[0] == '-' || str[0] == '+')
        start = 1;

    for (size_t i = start; i < str.length(); ++i)
    {
        //Checking for single decimal point
        if (str[i] == '.')
        {
            if (dotCount > 0 || i == start || i == str.length() - 1)
                return false;
            dotCount++;
            continue;
        }

        if (str[i] == 'f')
        {
            // Ensure 'f' only appears at the end of the number
            if (i != str.length() - 1)
                return false;
            continue;
        }
        if (!isdigit(str[i]))
            return false;
    }

    return dotCount == 1;
}


bool ScalarConverter::isValidInt(const std::string& str) {
    size_t start = 0;
    
    //Allowing optional sign
    if (str[0] == '-' || str[0] == '+')
        start = 1;
        
    //Ensuring only digits are present
    for (size_t i = start; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isValidChar(const std::string& str)
{
    return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "+inff" || 
            str == "-inf" || str == "-inff");
}

void ScalarConverter::handlePseudoLiteral(const std::string& arg)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    
    if (arg == "nan" || arg == "nanf")
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (arg == "+inf" || arg == "+inff")
    {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
    else
    {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

d_type ScalarConverter::determineType(const std::string& str)
{
    if (isPseudoLiteral(str))
        return INVALID;
    if (isValidChar(str))
        return CHAR;
    if (isValidInt(str))
        return INT;
    if (isValidFloat(str))
        return FLOAT;
    // Check if it's a valid double
    char* endPtr;
    strtod(str.c_str(), &endPtr);
    if (*endPtr == '\0')
        return DOUBLE;
    // If no type matches
    return INVALID;
}

void ScalarConverter::convertChar(const std::string& arg)
{
    char c = arg[0];
    //Prints character
    std::cout << "char: '" << c << "'\n";
    //Converts to int
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    //Converts to float
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    //Converts to double
    std::cout << "double: " << static_cast<double>(c) << std::endl;;
}

void ScalarConverter::convertInt(const std::string& arg)
{
    int value = static_cast<int>(atoi(arg.c_str()));
    
    std::cout << "char: ";
    //Checks if character is printable
    if (isprint(value))
        std::cout << "'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "Non displayable\n";
    //Prints int value
    std::cout << "int: " << value << '\n';
    //Converts to float
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;;
    //Converts to double
    std::cout << "double: " << static_cast<double>(value) << std::endl;;
}

void ScalarConverter::convertFloat(const std::string& arg)
{
    float value = static_cast<float>(atof(arg.c_str()));
    
    std::cout << "char: ";
    //Checks character printability
    if (value >= 0 && value <= 127 && isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "Non displayable\n";
    //Handles int conversion limitations
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "float: " << value << "f\n";
    //Converts to double
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& arg)
{
    double value = static_cast<double>(atof(arg.c_str()));
    
    std::cout << "char: ";
    if (value >= 0 && value <= 127 && isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "Non displayable\n";
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& arg)
{
    //Handles empty input
    if (arg.empty())
    {
        std::cout << "Empty input\n";
        return;
    }
    //Handles pseudo-literals
    if (isPseudoLiteral(arg))
    {
        handlePseudoLiteral(arg);
        return;
    }
    //Determines input type
    d_type type = determineType(arg);
    //Calls appropriate conversion method
    switch (type)
    {
        case CHAR:
            convertChar(arg);
            break;
        case INT:
            convertInt(arg);
            break;
        case FLOAT:
            convertFloat(arg);
            break;
        case DOUBLE:
            convertDouble(arg);
            break;
        default:
            std::cout << "Invalid input format\n";
            break;
    }
}
