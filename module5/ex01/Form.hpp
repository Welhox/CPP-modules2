/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:54 by clundber          #+#    #+#             */
/*   Updated: 2024/10/24 15:43:36 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>

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
	Form(std::string newName, unsigned int newGrade);
	Form(Form&);
	~Form();
	
	//overloads
	Form& operator=(Form&);
	
	//getters & setters
	const std::string getName();
	unsigned int getGrade();

	//exceptions
	class GradeTooHighException : public std::exception{
	public:
		const char * what() const noexcept override {
			return ("Waaaay too high grade!");
		}
	};
	class GradeTooLowException : public std::exception{
	public:
		const char * what() const noexcept override {
			return ("Waaaay too low grade!");
		}
	};
};