/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:40:47 by casimirri         #+#    #+#             */
/*   Updated: 2025/01/30 23:36:40 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <cmath>
#include <regex>

class BitcoinExchange
{
private:
    std::string queryPath;
    std::string valuePath;
    std::map<std::string, double> valueDB;

    
public:
    //constructors and destructors
	BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange(std::string newQuery);
    
    //operator overloads
    BitcoinExchange& operator=(const BitcoinExchange& other);
    
    //methods
    bool preParse();
    bool fileOK(std::string& path);
    bool mapDB();
    void printCSV();
    bool processQuery();
    bool validateDate(std::string& date);
    void processLine(std::string &date, std::string &value, std::string &line);
    bool validateValue(std::string &value, float &convertedValue);
    void printError(std::string error);
};