/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:14:20 by clundber          #+#    #+#             */
/*   Updated: 2024/11/04 16:26:39 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Serializer.hpp"

struct Data{
	std::string name;
	int	age;	
};

int	main()
{
	try
	{
	Data stored;
	stored.name = "Casi";
	stored.age = 20;
	Data *transfered;
	transfered = Serializer::deserialize(Serializer::serialize(&stored));
	std::cout << transfered->name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}