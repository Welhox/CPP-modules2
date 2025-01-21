/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 16:28:48 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>

int main()
{
	std::vector <int>container = {1, 2, 3, 4, 5};
	std::deque <int>container2 = {10, 20, 30, 40, 50};
	try
	{
		std::cout << easyfind(container, 4) << std::endl;
		std::cout << easyfind(container, 6) << std::endl;
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << easyfind(container2, 40) << std::endl;
		std::cout << easyfind(container2, 60) << std::endl;
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}