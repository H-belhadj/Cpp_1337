/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:20:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/12/03 17:20:26 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


// #pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>


class BitcoinExchange
{
    private:
        std::map <std::string, float> data;
        int readFlag;
    public:
        BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        BitcoinExchange(const BitcoinExchange& obj);
        ~BitcoinExchange();
        void setData(std::string date, float value);
        void readData(std::string input);
        std::map<std::string, float> GetData();
        std::vector<std::string> stringSplit(std::string str, char divider);
};


#endif