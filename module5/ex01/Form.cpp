/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:02:17 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 14:21:35 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _executeGrade(150)
{
	_signed = false;
}

Form::Form(std::string newName, unsigned int sign, unsigned int execute)
: _name(newName), _signGrade(sign), _executeGrade(execute)
{
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	_signed = false;
}

Form::Form(Form& other)
: _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	_signed = other._signed;
}

Form::~Form(){};

Form& Form::operator=(Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

const std::string Form::getName()
{
	return(_name);
}

unsigned int Form::getSignGrade()
{
	return(_signGrade);
}

unsigned int Form::getExecuteGrade()
{
	return (_executeGrade);
}

bool	Form::getSignStatus()
{
	return (_signed);
}

void Form::beSigned(Bureaucrat& bcrat)
{
	if (bcrat.getGrade() <= this->_signGrade)
	{
		if (this->_signed == false)
			this->_signed = true;
		else
			std::cout << "Form already signed" << std::endl;
	}
	else
		throw GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const noexcept {
	return ("Too high grade!");
}

const char * Form::GradeTooLowException::what() const noexcept {
	return ("Too low grade!");
}

std::ostream& operator<<(std::ostream& stream, Form& form){
	stream << form.getName() << ", Grade needed to sign " << form.getSignGrade() << " and to execute " << form.getExecuteGrade();
	if (form.getSignStatus())
		stream << " Form has been signed";
	else
		stream << " Form is unsigned";
	return (stream);
}