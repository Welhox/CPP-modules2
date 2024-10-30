/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:18 by clundber          #+#    #+#             */
/*   Updated: 2024/10/30 12:08:01 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"
# include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	AForm* robot = nullptr;
	AForm* shrub = nullptr;
	AForm* pardon = nullptr;
	try
	{
	robot = someRandomIntern.makeForm("RobotomyRequestFor", "Bender");
	shrub = someRandomIntern.makeForm("ShrubberyCreationForm", "airport");
	pardon = someRandomIntern.makeForm("PresidentialPardonForm", "BanditTim");
	Bureaucrat boss("Boss", 1);
	Bureaucrat noob("Noob", 130);
		boss.signForm(*robot);
		robot->beSigned(boss);
		boss.executeForm(*robot);
		boss.signForm(*shrub);
		shrub->beSigned(boss);
		boss.executeForm(*shrub);
		noob.signForm(*robot);
		robot->beSigned(noob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete robot;
	delete shrub;
	delete pardon;
}