/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:50:57 by clundber          #+#    #+#             */
/*   Updated: 2024/10/29 13:58:39 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other)
{
	this->_target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

void ShrubberyCreationForm::execution() const
{
	std::ofstream new_file(_target + "_shrubbery");
	if (!new_file.is_open())
        throw(std::invalid_argument("failed to create file"));
	else
	{
		new_file << "     *\n    ***\n   *****\n  *******\n *********\n***********\n    ||| " << '\n' << '\n';
		new_file << "     *\n    ***\n   *****\n  *******\n *********\n***********\n    ||| " << '\n';
	}
	new_file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
		execution();
}
