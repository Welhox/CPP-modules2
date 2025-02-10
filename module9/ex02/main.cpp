/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:17 by clundber          #+#    #+#             */
/*   Updated: 2025/02/10 19:28:13 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error");
		PmergeMe sort;
		sort.argVal(argv);
		sort.printBefore();
		sort.executeVector(argv);
		sort.executeList(argv);
		sort.printList();
		// sort.printVector();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << '\n';
		return(1);
	}
	return(0);
}