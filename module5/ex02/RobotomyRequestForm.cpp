/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:50:57 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 11:24:53 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <cstdlib>
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other)
{
	this->_target = other._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

void RobotomyRequestForm::execution() const
{
	std::cout << "Grousome drilling noises and a squealing robot " << '\n';
	std::srand(std::time(0));
	int random = std::rand();
	if (random %2 == 1)
		std::cout << _target << " has successfully been robotomized!" << '\n';
	else
		std::cout << "robotomy failed!" << '\n';	

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
		execution();
}
