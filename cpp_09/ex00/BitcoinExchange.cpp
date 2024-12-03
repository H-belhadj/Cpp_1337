/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:20:15 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/12/03 18:34:02 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

const char* WHITESPACE = " \t\n\r";

static std::string& left_trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(WHITESPACE));
    return str;
}

static std::string& right_trim(std::string& str)
{
    str.erase(str.find_last_not_of(WHITESPACE) + 1);
    return str;
}

static std::string& both_sides(std::string& str)
{
    return left_trim(right_trim(str));
}

BitcoinExchange::BitcoinExchange()
{
    this->readFlag = 1;
    std::ifstream file("./data.cvs");
    if(!file.is_open())
    {
        this->readFlag = 0;
        return;
    }
    std::string line;
    bool first_line = true;
    while(std::getline(file, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        size_t pos = line.find(',');
        if(pos == std::string::npos)
        {
            std::cerr << "Error : Parameter invalid " << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::stringstream ss(line.substr(pos + 1));
        float value;
        if (!(ss >> value))
        {
            std::cerr << "Error : could not parse value" << std::endl;
            continue;
        }
        this->setData(date, value);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
    {
        this->data = rhs.data;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

void BitcoinExchange::setData(std::string date, float value) 
{ 
    this->data.insert(std::make_pair(date, value)); 
}

std::map<std::string, float> BitcoinExchange::GetData() 
{ 
    return this->data; 
}

std::vector<std::string> BitcoinExchange::stringSplit(std::string str, char divider)
{
    std::vector<std::string> result;
    std::string current;
    
    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] != divider)
            current += str[i];
        else
        {
            result.push_back(current);
            current = "";
        }
    }
    
    if (!current.empty())
        result.push_back(current);
    
    return result;
}

void BitcoinExchange::readData(std::string input)
{
    std::ifstream file2(input.c_str());
    if(!file2.is_open())
    {
        this->readFlag = -1;
        return;
    }
    
    std::string line;
    bool first_line = true;
    
    while(std::getline(file2, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        
        std::vector<std::string> vectorLine = this->stringSplit(line, '|');
        
        if(vectorLine.size() < 2 || vectorLine[1].empty())
        {
            std::cout << "Error: bad input ==> " << line << std::endl;
            continue;
        }
        
        std::string trimmed_date = both_sides(vectorLine[0]);
        std::string trimmed_value = both_sides(vectorLine[1]);
        
        std::stringstream ss(trimmed_value);
        float value;
        if (!(ss >> value))
        {
            std::cout << "Error: not a number." << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, float>::iterator it = this->data.upper_bound(trimmed_date);
        if(it != this->data.begin())
        {
            --it;
            float exchange_rate = it->second;
            std::cout << trimmed_date << " => " << value << " = " 
                      << (value * exchange_rate) << std::endl;
        }
    }
    file2.close();
}