/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:44:20 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 14:54:19 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;

public:
	//constructors & destructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(ShrubberyCreationForm&);
	~ShrubberyCreationForm();
	
	//overloads
	ShrubberyCreationForm& operator=(ShrubberyCreationForm&);
	
	//functions
	void execute(Bureaucrat const & executor) const override;
	
};