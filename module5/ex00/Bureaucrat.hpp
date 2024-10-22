/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:23:15 by clundber          #+#    #+#             */
/*   Updated: 2024/10/22 14:45:57 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>

class Bureaucrat
{
private:
	const std::string name;	
	unsigned int grade;
	
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat&);
	~Bureaucrat();
	
	Bureaucrat& operator=(Bureaucrat&);
	
	const std::string getName();
	unsigned int getGrade();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);