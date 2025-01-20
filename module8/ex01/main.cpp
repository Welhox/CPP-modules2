/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/20 12:16:14 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		// Span sp = Span(500);
		Span sp(10);
		
		sp.addNumber(0);
		// sp.addNumber(99999999);
		// sp.addRange(100000, -100000);
		sp.addNumber(1200);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-11);
		sp.addNumber(-1000);
		// sp.printRange();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}