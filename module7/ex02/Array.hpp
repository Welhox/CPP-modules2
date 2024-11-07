/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:03:49 by clundber          #+#    #+#             */
/*   Updated: 2024/11/07 18:10:24 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
template<typename T>
class Array
{
private:
	T 		*_array;
	uint	_len;

public:
	//constructers and destructers
	Array();
	Array(uint len);
	Array(Array&);
	~Array();

	//operator overloads
	Array& operator=(Array&);
	T& operator[](uint);
	const T& operator[](uint) const;
	//methods
	uint size();
};
# include "Array.tpp"