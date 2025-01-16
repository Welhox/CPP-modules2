/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:17 by clundber          #+#    #+#             */
/*   Updated: 2025/01/16 14:29:49 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <iostream>
#include <algorithm>

class Span
{
private:
	unsigned int maxSize; 
	std::set <int>container;
	
public:	
	//constructors and destructors
	Span();
	Span(uint size);
	Span(Span&);
	~Span();

	//operator overloads
	Span& operator=(Span&);

	//methods
	void	addNumber(int newNumber);
	size_t	shortestSpan();
	size_t	longestSpan();
};