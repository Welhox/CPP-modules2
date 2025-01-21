/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 16:54:23 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		// Span sp = Span(500);
		Span sp(20);
		
		sp.addNumber(0);
		sp.addNumber(99999999);
		// sp.addRange(100000, -100000);
		sp.addRange(20, 30);
		sp.addNumber(1200);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-11);
		sp.addNumber(-1000);
		sp.printRange();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}