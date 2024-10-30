/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:03:37 by clundber          #+#    #+#             */
/*   Updated: 2024/10/30 18:18:22 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include "ScalarConverter.hpp"
# include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Incorrect ammount of arguments, one expected\n";	
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}