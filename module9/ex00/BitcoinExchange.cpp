/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:40:00 by casimirri         #+#    #+#             */
/*   Updated: 2025/01/31 00:11:21 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        //copy things
    }
    return (*this);
}

BitcoinExchange::BitcoinExchange(std::string newQuery): queryPath(newQuery), valuePath("data.csv") {}

bool BitcoinExchange::fileOK(std::string& path)
{
    std::filesystem::path filePath = path;
    if (!std::filesystem::exists(filePath))
        return false;
    std::ifstream file(filePath);
    if (!file.good())
        return false;
    if (std::filesystem::file_size(filePath) == 0)
        return false;
    return true;
}

bool BitcoinExchange::preParse()
{
    if (!fileOK(valuePath))
    {
        std::cerr << "Error: csv database error" << std::endl;
        return true;
    }
    if (!fileOK(queryPath))
    {
        std::cerr << "Error: bad or empty argument file" << std::endl;
        return true;
    }
    return false;
}

bool BitcoinExchange::mapDB()
{
    std::ifstream csv(valuePath);
    if (!csv.is_open())
    {
        std::cerr << "Error: csv database error" << std::endl;
        return 1;
    }
    
    std::string line, key, value;
    try
    {
        std::getline(csv, line);
        if (line != "date,exchange_rate")
        {
            std::cerr << "Error: csv database error2" << std::endl;
            return 1;
        }
        while(std::getline(csv, line))
        {
        std::stringstream lineStream(line);
        std::getline(lineStream, key, ',');
        std::getline(lineStream, value, ',');
        if (!lineStream.eof())
        {
            std::cerr << "Error: unexpected information in csv file." << std::endl;
            return (true);
        }
        valueDB[key] = stod(value);
        }
    }
    catch(const std::exception& e)
    {
         std::cerr << "Error: csv database error" << std::endl;
         return 1;
    }
    return (false);
}

void BitcoinExchange::printCSV()
{
    for(auto it : valueDB)
    {
        std::cout << "KEY = " << it.first;
        std::cout << " VALUE = " << it.second << std::endl;
    }
}
bool BitcoinExchange::validateDate(std::string& date)
{
    std::regex dateRegex(R"(\d{4}-\d{2}-\d{2}\s?)");
    if (!std::regex_match(date, dateRegex))
        return false;
    std::stringstream stream(date);
    int year, month, day;
    char delimiter1, delimiter2;
    stream >> year >> delimiter1 >> month >> delimiter2 >> day; 
    if (stream.fail() || delimiter1 != '-' || delimiter2 != '-' || month <= 0 \
        || month > 12 || day < 1 || year < 0)
        return false; 
    int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (monthArr[month -1] >= day)
        return true;
    if (month == 2 && day == 29)
    {
        if ((year % 4) == 0)
        {
            if (year % 100 == 0 && year % 400 != 0)
                return false;
            else
                return true;        
        }
    }
    return false;
        
}

bool BitcoinExchange::validateValue(std::string &value, float &convertedValue)
{
    std::regex intRegex(R"(\s?-?[0-9]+)");
    std::regex floatRegex(R"(\s?-?[0-9]+\.[0-9]+)");
    int temp;
    try
    {
        if (std::regex_match(value, intRegex))
        {
            temp = stoi(value);
            if (temp > 1001)
                temp = 1001;
            convertedValue = temp;
        }
        else if (std::regex_match(value, floatRegex))
            convertedValue = stof(value);
        else
            return false;
    }
    catch(const std::exception& e)
    {
        convertedValue = 1001;
        return true;
    }
    return true;
    //possible problem with large negative numbers, should maybe catch - in the beginning
}

void BitcoinExchange::printError(std::string error)
{
    std::cerr << error << std::endl;
}   

void BitcoinExchange::processLine(std::string &date, std::string &value, std::string &line)
{    
    float convertedValue;
    if (date.empty() || value.empty() || validateDate(date) == 0 || validateValue(value, convertedValue) == 0)
        return printError("Error: bad input => " + line);
    if (convertedValue > 1000)
        return printError("Error: too large a number.");
    if (convertedValue <= 0)
        return printError("Error: not a positive number.");
    auto it = valueDB.lower_bound(date);
    if ((it != valueDB.end() && date == it->first) || it == valueDB.begin())
    {
        std::cout << it->first << " => " << value << " = " << convertedValue * it->second << std::endl;
        return;
    }
    else
	{
		auto prev = std::prev(it);
		std::cout << prev->first << " => " << value << " = " << convertedValue * prev->second << std::endl;
        return;	
	}
}

bool BitcoinExchange::processQuery()
{
    std::ifstream query(queryPath);
    if (!query.is_open())
    {
        std::cerr << "Error: query failed to open." << std::endl;
        return 1;
    }
    std::string line, date, value;
    try
    {
        std::getline(query, line);
        if (line != "date | value")
        {    
            std::cerr << "Error: incorrect query file" << std::endl;
            return 1;
        }
        while(std::getline(query, line))
        {
            std::stringstream lineStream(line);
            if (!lineStream.eof())
                std::getline(lineStream, date, '|');
            if (!lineStream.eof())
                std::getline(lineStream, value);
            if (date.back() == ' ')
                date = date.substr(0, date.size() -1);
            processLine(date, value, line);
            date.erase();
            value.erase();
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}