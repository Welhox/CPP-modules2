/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:44:20 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 15:37:16 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "AForm.hpp"
# include <string>

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;

public:
	//constructors & destructors
	RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(RobotomyRequestForm&);
	~RobotomyRequestForm();
	
	//overloads
	RobotomyRequestForm& operator=(RobotomyRequestForm&);
	
	//functions
	void execute(Bureaucrat const & executor) const override;
	void execution() const;
};