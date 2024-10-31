/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:06:45 by clundber          #+#    #+#             */
/*   Updated: 2024/10/31 16:30:09 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <cstdint>

struct Data;

class Serializer
{
private:
	//constructors and destructor
	Serializer(){};
	//Serializer(Serializer&){};
	~Serializer(){};
	
public:
	//overloads
	//Serializer& operator=(Serializer&){};

	//methods
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};