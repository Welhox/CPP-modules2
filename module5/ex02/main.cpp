/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:40:36 by clundber          #+#    #+#             */
/*   Updated: 2024/10/30 11:48:39 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm pensas("hive");
	Bureaucrat boss("Boss", 1);
	Bureaucrat noob("noob", 145);

	ShrubberyCreationForm tree("park");
	try
	{
		boss.signForm(pensas);
		pensas.beSigned(boss);
		boss.executeForm(pensas);
		tree.execute(boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{	
	RobotomyRequestForm drill("Bender");
	boss.signForm(drill);
	drill.beSigned(boss);
	boss.executeForm(drill);
	boss.executeForm(drill);
	boss.executeForm(drill);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{	
	PresidentialPardonForm casi("Casi");
	boss.signForm(casi);
	casi.beSigned(boss);
	boss.executeForm(casi);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}