/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:23:31 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/12/03 22:23:39 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

class BitcoinExchange {
private:
    std::map<std::string, double> data;//he key is a std::string representing a date (e.g., "2021-01-01"), and the value is a double representing the Bitcoin rate on that date.

    void validateInputFile(std::ifstream& file);
    std::string trim(const std::string& str);
    bool parseInputLine(const std::string& line, std::string& date, double& value);
    bool validateDate(const std::string& date);
    bool validateValue(const double value);
    double findClosestBitcoinRate(const std::string& date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processExchangeFile(const std::string& filename);
};

#endif