/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:32:34 by casimirri         #+#    #+#             */
/*   Updated: 2024/11/19 11:09:49 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
# include <iostream>

template <typename T>
void print(T var)
{
	std::cout << var << std::endl;
}

template <typename T>
void add(T& var)
{
	var += 1;
}

int main()
{
	try
	{
		std::string array[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero"};
		int	len = 10;
		iter(array, len, print<std::string>);
		int array2[5] = {100, 200, 300, 400, 500};
		int len2 = 5;
		iter(array2, len2, add<int>);
		iter(array2, len2, print<int>);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}