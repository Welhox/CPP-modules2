/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:23:15 by clundber          #+#    #+#             */
/*   Updated: 2024/10/24 15:43:54 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>

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

	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat);