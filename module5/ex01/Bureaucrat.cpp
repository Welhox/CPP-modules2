/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:48 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 13:57:58 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade): name(newName), grade(newGrade){

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat& other): name(other.name), grade(other.grade){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other){
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

const std::string Bureaucrat::getName(){
	return (this->name);
}

unsigned int Bureaucrat::getGrade(){
	return(this->grade);
}

void Bureaucrat::incrementGrade(){
	grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
	grade--;
	if (grade > 150)
		throw GradeTooHighException();
}

void Bureaucrat::signForm(Form& form)
{
	if (this->getGrade() <= form.getSignGrade() && !form.getSignStatus())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else if (this->getGrade() > form.getSignGrade())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " due too low Bureaucrat Grade" << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " due to form already signed" << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Waaaay too high grade!");
}

const char * Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Waaaay too low grade!");
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat){
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade(); 
	return (stream);
}

