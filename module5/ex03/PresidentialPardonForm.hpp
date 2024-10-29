/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:44:20 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 15:37:16 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm: public AForm
{
private:
	std::string _target;

public:
	//constructors & destructors
	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(PresidentialPardonForm&);
	~PresidentialPardonForm();
	
	//overloads
	PresidentialPardonForm& operator=(PresidentialPardonForm&);
	
	//functions
	void execute(Bureaucrat const & executor) const override;
	void execution() const;
};