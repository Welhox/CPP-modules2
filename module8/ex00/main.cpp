/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/16 11:25:58 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

int main()
{
	std::vector <int>container = {1, 2, 3, 4, 5};
	try
	{
		std::cout << easyfind(container, 4) << std::endl;
		std::cout << easyfind(container, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}