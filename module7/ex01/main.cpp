/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:32:34 by casimirri         #+#    #+#             */
/*   Updated: 2024/11/07 17:22:37 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
# include <iostream>

void printStr(std::string str)
{
	std::cout << str << std::endl;
}

void printint(int num)
{
	std::cout << num << std::endl;
}

// template <typename T>
void add(int& var)
{
	var += 1;
}


int main()
{
	try
	{
		std::string array[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero"};
		int	len = 10;
		iter(array, len, printStr);
		int array2[5] = {100, 200, 300, 400, 500};
		int len2 = 5;
		iter(array2, len2, add);
		iter(array2, len2, printint);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}