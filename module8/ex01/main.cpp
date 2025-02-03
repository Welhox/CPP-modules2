/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:36:57 by clundber          #+#    #+#             */
/*   Updated: 2025/02/03 10:27:15 by clundber         ###   ########.fr       */
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
		// sp.printRange();
		std::cout << "SHORTEST SPAN = " << sp.shortestSpan() << std::endl;
		std::cout << "LONGEST SPAN = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "------------------------------------" << std::endl;
	try
	{
		Span sp1; //dfaults to a capacity of 1
		sp1.addNumber(20);
		sp1.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------" << std::endl;
	std::cout << "COPY CONSTRUCTOR AND = OPERATOR OVERLOAD:" << std::endl;
	try
	{
		Span sp2(20);
		sp2.addRange(1, 5);
		Span sp3(sp2);
		Span sp4;
		sp4 = sp2;
		std::cout << "sp2------------------------------------" << std::endl;
		sp2.printRange();
		std::cout << "sp3------------------------------------" << std::endl;
		sp3.printRange();
		std::cout << "sp4------------------------------------" << std::endl;
		sp4.printRange();
		std::cout << "------------------------------------" << std::endl;
		std::cout << "LONGEST SPAN = " << sp4.longestSpan() << std::endl;
		sp3.addRange(-100, 100); //this will throw, due too many numbers for range size
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp5;
		std::cout << "SHORTEST SPAN = " << sp5.shortestSpan() << std::endl;
		//this throws due empty span
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
		
}