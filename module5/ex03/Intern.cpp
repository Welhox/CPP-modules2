/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:52:14 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 14:15:47 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern& other)
{
	if (this != &other)
		;
}

Intern::~Intern(){
}

Intern& Intern::operator=(Intern& other)
{
	if (this != &other)
		;
	return (*this);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"}; 
	int filter = 0;
	while (filter < 3 && forms[filter].compare(form))
		filter++;
	switch (filter)
	{
		case 0 :
			return (new PresidentialPardonForm(target));
			break;
		case 1 :
			return (new RobotomyRequestForm(target));
			break;
		case 2 :
			return (new ShrubberyCreationForm(target));
			break;						
		default :
			std::cout << "Form not found\n";
			return(nullptr);
	}
}