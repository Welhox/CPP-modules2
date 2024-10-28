/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:40:36 by clundber          #+#    #+#             */
/*   Updated: 2024/10/28 15:46:39 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

int main()
{
	ShrubberyCreationForm pensas("hive");
	Bureaucrat boss("Boss", 1);
	boss.signForm(pensas);
	pensas.beSigned(boss);
	pensas.execute(boss);
	ShrubberyCreationForm tree("park");
	try
	{
		tree.execute(boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}