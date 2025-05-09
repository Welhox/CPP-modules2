/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:48:40 by clundber          #+#    #+#             */
/*   Updated: 2025/01/16 11:25:25 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>

template <typename T> 
int easyfind(T container, int key)
{
	for (auto it : container)
	{
		if (it == key)
			return (it);
	}
	throw std::invalid_argument("not found");
};