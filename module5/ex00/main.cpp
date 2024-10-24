/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:09 by clundber          #+#    #+#             */
/*   Updated: 2024/10/24 15:13:12 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

int	main()
{
	Bureaucrat casi("casi", 2);
	
	std::cout << casi << std::endl;
	
	casi.incrementGrade();

	std::cout << casi << std::endl;
	try
	{
		casi.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat papi("papi", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat kissa("kissa", 23);
		std::cout << kissa.getName() << '\n';
		Bureaucrat koira(kissa);
		std::cout << koira << std::endl;
		Bureaucrat kotka;
		std::cout << kotka << std::endl;	
		kotka = kissa;
		std::cout << kotka << std::endl;		
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}