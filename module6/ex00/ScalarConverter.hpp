/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:30 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:55 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>

class ScalarConverter
{
private:

public:

	//constructors and destructor
	ScalarConverter();
	ScalarConverter(ScalarConverter&);
	~ScalarConverter();
	
	//overloads
	ScalarConverter& operator=(ScalarConverter&);

	//methods
	static void convert(std::string input);
};