/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:50:57 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 11:24:53 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other): AForm(other)
{
	this->_target = other._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

void PresidentialPardonForm::execution() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
		execution();
}
