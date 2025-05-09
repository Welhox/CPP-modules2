/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:54 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 14:10:31 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const				std::string _name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;
	
public:
	//constructors and destructor
	Form();
	Form(std::string newName, unsigned int sign, unsigned int execute);
	Form(Form&);
	~Form();
	
	//overloads
	Form& operator=(Form&);
	
	//getters & setters
	const std::string getName();
	unsigned int getSignGrade();
	unsigned int getExecuteGrade();
	bool	getSignStatus();

	//functions
	void beSigned(Bureaucrat&);

	//exceptions
	class GradeTooHighException : public std::exception{
	public:
		const char * what() const noexcept override;
	};
	class GradeTooLowException : public std::exception{
	public:
		const char * what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& stream, Form& form);