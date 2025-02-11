/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:30:21 by casimirri         #+#    #+#             */
/*   Updated: 2025/02/11 15:55:28 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
		return 0;
	try
	{
		RPN rpn(argv[1]);
		rpn.calculate();
		// rpn.printStack();
		rpn.printSum();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << '\n';
		return 1;
	}
	
	return 0;
}