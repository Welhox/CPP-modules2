/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:18:18 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 14:22:58 by clundber         ###   ########.fr       */
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
	AForm* robot;
	AForm* shrub;
	AForm* pardon;
	robot = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	shrub = someRandomIntern.makeForm("ShrubberyCreationForm", "airport");
	pardon = someRandomIntern.makeForm("PresidentialPardonForm", "BanditTim");
	Bureaucrat boss("Boss", 1);
	Bureaucrat noob("Noob", 130);
	
	try
	{
		boss.signForm(*robot);
		robot->beSigned(boss);
		robot->execute(boss);
		boss.signForm(*shrub);
		shrub->beSigned(boss);
		shrub->execute(boss);
		// pardon->execute(boss);
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