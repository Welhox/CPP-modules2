/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:30:48 by casimirri         #+#    #+#             */
/*   Updated: 2025/01/30 22:25:10 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: incorrect number of arguments." << std::endl;
        return 1;
    }
    BitcoinExchange exchange(argv[1]);
    if (exchange.preParse())
        return 1;
    if (exchange.mapDB())
        return 1;
    exchange.processQuery();
    // exchange.printCSV();
}