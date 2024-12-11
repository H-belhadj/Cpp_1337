#include "BitcoinExchange.hpp"
#include <sstream>
#include <algorithm>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open())
    {
        std::cerr << "Error: Cannot open data.csv" << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(dataFile, line); // Skip header

    while (std::getline(dataFile, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            std::string date = line.substr(0, commaPos);
            double rate = std::atof(line.substr(commaPos + 1).c_str());
            data[date] = rate;
        }
    }
    dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        data = other.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::validateInputFile(std::ifstream& file)
{
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        exit(1);
    }

    std::string header;
    std::getline(file, header);
    if (header != "date | value")
    {
        std::cerr << "Error: Invalid input file format." << std::endl;
        exit(1);
    }
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");

    if (first == std::string::npos || last == std::string::npos)
        return "";

    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& date, double& value)
{
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos)
    {
        std::cerr << "Error: Bad input => " << line << std::endl;
        return false;
    }

    date = trim(line.substr(0, pipePos));
    std::string valueStr = trim(line.substr(pipePos + 1));
    
    char* endptr;
    value = std::strtod(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0')
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char* endptr;
    
    year = std::strtol(date.substr(0, 4).c_str(), &endptr, 10);
    if (*endptr != '\0')
        return false;
    
    month = std::strtol(date.substr(5, 2).c_str(), &endptr, 10);
    if (*endptr != '\0') 
        return false;
    
    day = std::strtol(date.substr(8, 2).c_str(), &endptr, 10);
    if (*endptr != '\0')
        return false;

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::validateValue(const double value)
{
    if (value < 0) {
        std::cerr << "Error: Not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: Too large number." << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::findClosestBitcoinRate(const std::string& date)
{
    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if (it == data.begin()) return it->second;
    if (it == data.end())
    {
        --it;
        return it->second;
    }
    if (it->first != date)
        --it;
    return it->second;
}

void BitcoinExchange::processExchangeFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    validateInputFile(file);

    std::string line, date;
    double value;

    while (std::getline(file, line))
    {
        if (line.empty() || line == "date | value")
            continue;

        if (!parseInputLine(line, date, value))
            continue;

        if (!validateDate(date) || !validateValue(value))
            continue;

        double rate = findClosestBitcoinRate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }

    file.close();
}