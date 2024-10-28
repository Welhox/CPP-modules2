/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:45 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 14:17:10 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"
int	main()
{
	try
	{
	Bureaucrat freeman("Freeman", 20);
	Form freecard;
	std::cout << freecard << std::endl;
	Form goodform("goodform", 50, 35);
	std::cout << goodform << std::endl;
	Form dupeform(goodform);
	std::cout << dupeform << std::endl;
	freeman.signForm(goodform);
	goodform.beSigned(freeman);
	std::cout << goodform << std::endl;
	Form badform("baad", 30, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form hardform("Hardform", 2, 1);
	Bureaucrat badcrat("Badcrat", 100);
	std::cout << hardform << std::endl;
	try
	{
	badcrat.signForm(hardform);
	hardform.beSigned(badcrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << hardform << std::endl;
}