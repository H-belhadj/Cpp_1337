/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:20:15 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/12/03 17:36:29 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinEXchange.hpp"

const char* WHITESPACE = " \t\n\r";


static std::string& left_trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(WHITESPACE));
    return str;
}

static std::string& right_trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(WHITESPACE) + 1);
    return str;
}

static std::string & both_sides(std::string& str)
{
    return left_trim(right_trim(str));
}

BitcoinExchange::BitcoinExchange()
{
    int i = 0;
    this->readFlag = 1;
    std::ifstream file("./data.cvs");
    if(!file.is_open())
    {
        this->readFlag = 0;
        return ;
    }
    std::string line;
    while(std::getline(file, line))
    {
        if (i == 0)
        {
            i = 1;
            continue;
        }
        size_t pos = line.find(',');
        if(pos == std::string::npos)
        {
            std::cerr << "Error : Paramter invalid " << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        double value;
        try
        {
            value = std::stod(line.substr(pos + 1));
        }
        catch(const std::exception& e)
        {
            (void)a;
            std::cerr << "Error : could not parse value" << '\n';
            countinue;
        }
        this->setData(date, value);
    }
    file.close();
}