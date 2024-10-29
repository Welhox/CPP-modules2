/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:52:18 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 14:01:51 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

class AForm;

class Intern
{
private:

public:
	//constructers and destructer
	Intern();
	Intern(Intern&);
	~Intern();
	
	//overloads
	Intern& operator=(Intern&);

	//functions
	AForm *makeForm(std::string form, std::string target);
};