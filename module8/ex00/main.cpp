/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/02/03 10:04:36 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>

int main()
{
	std::vector <int>container = {1, 2, 3, 4, 5};
	std::deque <int>container2 = {10, 20, 30, 40, 50};
	std::list <int>container3;
	
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
	
	try
	{
		std::cout << easyfind(container3, 40) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}