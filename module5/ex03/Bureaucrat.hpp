/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:23:15 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 15:42:03 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name;	
	unsigned int grade;
	
public:
	//constructors and destructor
	Bureaucrat();
	Bureaucrat(std::string newName, unsigned int newGrade);
	Bureaucrat(Bureaucrat&);
	~Bureaucrat();
	
	//overloads
	Bureaucrat& operator=(Bureaucrat&);
	
	//getters & setters
	const std::string getName();
	unsigned int getGrade();
	unsigned int getGrade() const;

	//exceptions
	class GradeTooHighException : public std::exception{
	public:
		const char * what() const noexcept override;
	};
	class GradeTooLowException : public std::exception{
	public:
		const char * what() const noexcept override;
	};

	//functions
	void signForm(AForm&);
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat);