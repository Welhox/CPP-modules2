/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:57 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 15:06:10 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

//constructors and destructor
ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter&){};

ScalarConverter::~ScalarConverter(){};
	
//overloads
ScalarConverter& ScalarConverter::operator=(ScalarConverter& other){
	if (this != &other)
		;
	return(*this);
}

//methods
static void convert(std::string input)
{
	
}