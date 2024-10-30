/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:30 by clundber          #+#    #+#             */
/*   Updated: 2024/10/30 18:18:07 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>
# include <climits>
# include <iomanip>
# define _int 0
# define _float 1
# define _double 2
# define _char 3
# define _wrong 4

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter&);

public:
	//constructors and destructor
	~ScalarConverter();
	
	//overloads
	ScalarConverter& operator=(ScalarConverter&);

	//methods
	static void convert(std::string input);
};