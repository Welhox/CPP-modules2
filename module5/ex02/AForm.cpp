/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:02:17 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 13:48:25 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _executeGrade(150)
{
	_signed = false;
}

AForm::AForm(std::string newName, unsigned int sign, unsigned int execute)
: _name(newName), _signGrade(sign), _executeGrade(execute)
{
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm& other)
: _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	_signed = other._signed;
}

AForm::~AForm(){};

AForm& AForm::operator=(AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

const std::string AForm::getName()
{
	return(_name);
}

unsigned int AForm::getSignGrade()
{
	return(_signGrade);
}

unsigned int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

unsigned int AForm::getExecuteGrade()
{
	return (_executeGrade);
}

bool	AForm::getSignStatus() const
{
	return (_signed);
}

bool	AForm::getSignStatus()
{
	return (_signed);
}

void AForm::beSigned(Bureaucrat& bcrat)
{
	if (bcrat.getGrade() <= this->_signGrade)
	{
		if (this->_signed == false)
			this->_signed = true;
		else
			std::cout << "form already signed" << std::endl;
	}
	else
		throw GradeTooLowException();
}

// void AForm::execute(Bureaucrat const & executor) const
// {
// 	if (!this->_signed)
// 		throw NotSignedException();
// 	else if (executor.getGrade() > this->_executeGrade)
// 		throw GradeTooLowException();
// 	else

// }

const char * AForm::NotSignedException::what() const noexcept {
	return ("Form not signed!");
}

const char * AForm::GradeTooHighException::what() const noexcept {
	return ("Too high grade!");
}

const char * AForm::GradeTooLowException::what() const noexcept {
	return ("Too low grade!");
}

std::ostream& operator<<(std::ostream& stream, AForm& AForm){
	stream << AForm.getName() << ", Grade needed to sign " << AForm.getSignGrade() << " and to execute " << AForm.getExecuteGrade();
	if (AForm.getSignStatus())
		stream << " form has been signed";
	else
		stream << " form is unsigned";
	return (stream);
}